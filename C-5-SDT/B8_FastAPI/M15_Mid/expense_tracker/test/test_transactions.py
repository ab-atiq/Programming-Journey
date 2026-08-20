from datetime import date

from fastapi import status

from test.test_main import client
from main import app
from routers.auth import get_current_user
from database import SessionLocal
from models import Transactions, Users

TEST_USER_ID = 9999
TEST_TRANSACTION_ID = 9999


def override_get_current_user():
    """Bypass real JWT validation for tests - pretend we're already logged in."""
    return {"id": TEST_USER_ID, "username": "pytest_user"}


app.dependency_overrides[get_current_user] = override_get_current_user


def setup_module(module):
    """Runs once before all tests in this file: make sure a dummy user +
    one seed transaction exist so read/update/delete tests have data."""
    db = SessionLocal()

    # clean up leftovers from a previous failed run
    db.query(Transactions).filter(Transactions.owner_id == TEST_USER_ID).delete()
    db.query(Users).filter(Users.id == TEST_USER_ID).delete()
    db.commit()

    user = Users(
        id=TEST_USER_ID,
        username="pytest_user",
        email="pytest_user@example.com",
        hashed_password="not-used-because-auth-is-overridden",
    )
    db.add(user)

    transaction = Transactions(
        id=TEST_TRANSACTION_ID,
        title="Seed Transaction",
        amount=250.0,
        type="expense",
        category="Testing",
        date=date(2026, 8, 1),
        owner_id=TEST_USER_ID,
    )
    db.add(transaction)
    db.commit()
    db.close()


def teardown_module(module):
    """Clean up everything this test file created."""
    db = SessionLocal()
    db.query(Transactions).filter(Transactions.owner_id == TEST_USER_ID).delete()
    db.query(Users).filter(Users.id == TEST_USER_ID).delete()
    db.commit()
    db.close()


# ---------------------------------------------------------------------------
# 1. Get all transactions
# ---------------------------------------------------------------------------
def test_get_all_transactions():
    response = client.get("/transactions")
    assert response.status_code == status.HTTP_200_OK
    assert isinstance(response.json(), list)
    assert any(t["id"] == TEST_TRANSACTION_ID for t in response.json())


# ---------------------------------------------------------------------------
# 2. Get a specific transaction
# ---------------------------------------------------------------------------
def test_get_specific_transaction():
    response = client.get(f"/transactions/{TEST_TRANSACTION_ID}")
    assert response.status_code == status.HTTP_200_OK
    assert response.json()["id"] == TEST_TRANSACTION_ID
    assert response.json()["title"] == "Seed Transaction"


def test_get_specific_transaction_not_found():
    response = client.get("/transactions/1234567")
    assert response.status_code == status.HTTP_404_NOT_FOUND


# ---------------------------------------------------------------------------
# 3. Create a transaction
# ---------------------------------------------------------------------------
def test_create_transaction():
    db = SessionLocal()
    db.query(Transactions).filter(Transactions.id == 8888).delete()
    db.commit()
    db.close()

    request_data = {
        "title": "Bus Fare",
        "amount": 45.5,
        "type": "expense",
        "category": "Transport",
        "date": "2026-08-15",
    }
    response = client.post("/transactions", json=request_data)
    assert response.status_code == status.HTTP_201_CREATED

    body = response.json()
    assert body["title"] == "Bus Fare"
    assert body["owner_id"] == TEST_USER_ID

    # cleanup the transaction created by this test
    db = SessionLocal()
    db.query(Transactions).filter(Transactions.id == body["id"]).delete()
    db.commit()
    db.close()


def test_create_transaction_invalid_amount():
    request_data = {
        "title": "Bad Amount",
        "amount": -20,
        "type": "expense",
        "category": "Food",
        "date": "2026-08-15",
    }
    response = client.post("/transactions", json=request_data)
    assert response.status_code == status.HTTP_422_UNPROCESSABLE_ENTITY


# ---------------------------------------------------------------------------
# 4. Update a transaction
# ---------------------------------------------------------------------------
def test_update_transaction():
    request_data = {"title": "Seed Transaction - Updated", "amount": 300.0}
    response = client.put(f"/transactions/{TEST_TRANSACTION_ID}", json=request_data)
    assert response.status_code == status.HTTP_200_OK
    assert response.json()["title"] == "Seed Transaction - Updated"
    assert response.json()["amount"] == 300.0


def test_update_transaction_not_found():
    response = client.put("/transactions/1234567", json={"title": "Nope"})
    assert response.status_code == status.HTTP_404_NOT_FOUND


# ---------------------------------------------------------------------------
# 5. Delete a transaction
# ---------------------------------------------------------------------------
def test_delete_transaction():
    db = SessionLocal()
    db.query(Transactions).filter(Transactions.id == 7777).delete()
    db.commit()
    temp = Transactions(
        id=7777,
        title="Temp Delete Me",
        amount=10.0,
        type="expense",
        category="Misc",
        date=date(2026, 8, 10),
        owner_id=TEST_USER_ID,
    )
    db.add(temp)
    db.commit()
    db.close()

    response = client.delete("/transactions/7777")
    assert response.status_code == status.HTTP_200_OK
    assert response.json() == {"detail": "Transaction deleted successfully"}


def test_delete_transaction_not_found():
    response = client.delete("/transactions/1234567")
    assert response.status_code == status.HTTP_404_NOT_FOUND
