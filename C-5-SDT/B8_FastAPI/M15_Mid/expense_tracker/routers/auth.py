import os
from datetime import datetime, timedelta, timezone
from typing import Annotated

from fastapi import APIRouter, Depends, HTTPException, status
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from jose import jwt, JWTError
from passlib.context import CryptContext
from sqlalchemy.orm import Session

from database import SessionLocal
from models import Users
from schemas import UserCreate, UserOut, Token

router = APIRouter(prefix="/auth", tags=["Auth"])

# ---------------------------------------------------------------------------
# Security config
# ---------------------------------------------------------------------------
SECRET_KEY = os.getenv("SECRET_KEY", "86746eeb8285ca279c6251e0bd83cdd50c88027b934a93f19d8b9af782139516")
ALGORITHM = "HS256"
ACCESS_TOKEN_EXPIRE_MINUTES = 30

bcrypt_context = CryptContext(schemes=["bcrypt"], deprecated="auto")
oauth2_bearer = OAuth2PasswordBearer(tokenUrl="auth/login")


def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()


db_dependency = Annotated[Session, Depends(get_db)]


# ---------------------------------------------------------------------------
# Helper functions
# ---------------------------------------------------------------------------
def authenticate_user(username: str, password: str, db: Session):
    user = db.query(Users).filter(Users.username == username).first()
    if not user:
        return False
    if not bcrypt_context.verify(password, user.hashed_password):
        return False
    return user


def create_access_token(username: str, user_id: int, expires_delta: timedelta):
    encode = {"sub": username, "id": user_id}
    expires = datetime.now(timezone.utc) + expires_delta
    encode.update({"exp": expires})
    return jwt.encode(encode, SECRET_KEY, algorithm=ALGORITHM)


def get_current_user(token: Annotated[str, Depends(oauth2_bearer)]):
    """Dependency used by every protected route across the app."""
    credentials_exception = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail="Could not validate credentials",
        headers={"WWW-Authenticate": "Bearer"},
    )
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        username: str = payload.get("sub")
        user_id: int = payload.get("id")
        if username is None or user_id is None:
            raise credentials_exception
        return {"username": username, "id": user_id}
    except JWTError:
        raise credentials_exception


user_dependency = Annotated[dict, Depends(get_current_user)]


# ---------------------------------------------------------------------------
# Routes
# ---------------------------------------------------------------------------
@router.post("/register", response_model=UserOut, status_code=status.HTTP_201_CREATED)
def register(new_user: UserCreate, db: db_dependency):
    """Register a new user. The hashed password is NEVER returned."""

    existing = (
        db.query(Users)
        .filter((Users.username == new_user.username) | (Users.email == new_user.email))
        .first()
    )
    if existing:
        raise HTTPException(
            status_code=status.HTTP_400_BAD_REQUEST,
            detail="Username or email already registered",
        )

    user_model = Users(
        username=new_user.username,
        email=new_user.email,
        hashed_password=bcrypt_context.hash(new_user.password),
    )

    db.add(user_model)
    db.commit()
    db.refresh(user_model)

    return user_model  # response_model=UserOut strips hashed_password automatically


@router.post("/login", response_model=Token)
def login(db: db_dependency, form_data: Annotated[OAuth2PasswordRequestForm, Depends()]):
    """Verify credentials and return a JWT access token."""

    user = authenticate_user(form_data.username, form_data.password, db)
    if not user:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Incorrect username or password",
            headers={"WWW-Authenticate": "Bearer"},
        )

    token = create_access_token(
        user.username, user.id, timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
    )

    return {"access_token": token, "token_type": "bearer"}
