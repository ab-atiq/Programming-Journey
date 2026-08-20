from typing import Annotated, Optional

from fastapi import APIRouter, Depends, HTTPException, status
from sqlalchemy.orm import Session

from database import SessionLocal
from models import Transactions
from schemas import TransactionCreate, TransactionUpdate, TransactionOut
from routers.auth import get_current_user

router = APIRouter(prefix="/transactions", tags=["Transactions"])


def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()


db_dependency = Annotated[Session, Depends(get_db)]
user_dependency = Annotated[dict, Depends(get_current_user)]


# ---------------------------------------------------------------------------
# Create
# ---------------------------------------------------------------------------
@router.post("", response_model=TransactionOut, status_code=status.HTTP_201_CREATED)
@router.post("/", response_model=TransactionOut, status_code=status.HTTP_201_CREATED, include_in_schema=False)
def create_transaction(user: user_dependency, db: db_dependency, new_transaction: TransactionCreate):
    transaction_model = Transactions(
        **new_transaction.model_dump(), owner_id=user.get("id")
    )
    db.add(transaction_model)
    db.commit()
    db.refresh(transaction_model)
    return transaction_model


# ---------------------------------------------------------------------------
# Filter  --  IMPORTANT: must be declared BEFORE /{transaction_id}
# otherwise FastAPI will try to parse "filter" as an int transaction_id.
# ---------------------------------------------------------------------------
@router.get("/filter", response_model=list[TransactionOut])
def filter_transactions(
    user: user_dependency,
    db: db_dependency,
    type: Optional[str] = None,
    category: Optional[str] = None,
    minimum_amount: Optional[float] = None,
    maximum_amount: Optional[float] = None,
):
    query = db.query(Transactions).filter(Transactions.owner_id == user.get("id"))

    if type is not None:
        query = query.filter(Transactions.type == type)
    if category is not None:
        query = query.filter(Transactions.category.ilike(category))
    if minimum_amount is not None:
        query = query.filter(Transactions.amount >= minimum_amount)
    if maximum_amount is not None:
        query = query.filter(Transactions.amount <= maximum_amount)

    return query.all()


# ---------------------------------------------------------------------------
# Read all (current user only)
# ---------------------------------------------------------------------------
@router.get("", response_model=list[TransactionOut])
@router.get("/", response_model=list[TransactionOut], include_in_schema=False)
def read_transactions(user: user_dependency, db: db_dependency):
    return db.query(Transactions).filter(Transactions.owner_id == user.get("id")).all()


# ---------------------------------------------------------------------------
# Read one
# ---------------------------------------------------------------------------
@router.get("/{transaction_id}", response_model=TransactionOut)
def read_transaction(user: user_dependency, db: db_dependency, transaction_id: int):
    transaction = (
        db.query(Transactions)
        .filter(Transactions.owner_id == user.get("id"))
        .filter(Transactions.id == transaction_id)
        .first()
    )
    if transaction is None:
        raise HTTPException(status_code=404, detail="Transaction not found")
    return transaction


# ---------------------------------------------------------------------------
# Update
# ---------------------------------------------------------------------------
@router.put("/{transaction_id}", response_model=TransactionOut)
def update_transaction(
    user: user_dependency,
    db: db_dependency,
    transaction_id: int,
    update_data: TransactionUpdate,
):
    transaction = (
        db.query(Transactions)
        .filter(Transactions.owner_id == user.get("id"))
        .filter(Transactions.id == transaction_id)
        .first()
    )
    if transaction is None:
        raise HTTPException(status_code=404, detail="Transaction not found")

    for key, value in update_data.model_dump(exclude_unset=True).items():
        setattr(transaction, key, value)

    db.commit()
    db.refresh(transaction)
    return transaction


# ---------------------------------------------------------------------------
# Delete
# ---------------------------------------------------------------------------
@router.delete("/{transaction_id}", status_code=status.HTTP_200_OK)
def delete_transaction(user: user_dependency, db: db_dependency, transaction_id: int):
    transaction = (
        db.query(Transactions)
        .filter(Transactions.owner_id == user.get("id"))
        .filter(Transactions.id == transaction_id)
        .first()
    )
    if transaction is None:
        raise HTTPException(status_code=404, detail="Transaction not found")

    db.delete(transaction)
    db.commit()

    return {"detail": "Transaction deleted successfully"}
