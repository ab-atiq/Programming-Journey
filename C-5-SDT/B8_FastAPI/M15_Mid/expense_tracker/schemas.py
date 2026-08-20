import datetime as dt
from typing import Optional, Literal
from pydantic import BaseModel, EmailStr, Field


# ---------------------------------------------------------------------------
# Auth / User schemas
# ---------------------------------------------------------------------------
class UserCreate(BaseModel):
    username: str = Field(min_length=3, max_length=50)
    email: EmailStr
    password: str = Field(min_length=6)


class UserOut(BaseModel):
    id: int
    username: str
    email: EmailStr

    class Config:
        from_attributes = True  # (orm_mode for pydantic v1)


class Token(BaseModel):
    access_token: str
    token_type: str


# ---------------------------------------------------------------------------
# Transaction schemas
# ---------------------------------------------------------------------------
class TransactionCreate(BaseModel):
    title: str = Field(min_length=1, max_length=100)
    amount: float = Field(gt=0, description="Amount must be a positive number")
    type: Literal["income", "expense"]
    category: str = Field(min_length=1, max_length=50)
    date: dt.date


class TransactionUpdate(BaseModel):
    title: Optional[str] = Field(default=None, min_length=1, max_length=100)
    amount: Optional[float] = Field(default=None, gt=0)
    type: Optional[Literal["income", "expense"]] = Field(default=None)
    category: Optional[str] = Field(default=None, min_length=1, max_length=50)
    date: Optional[dt.date] = Field(default=None)


class TransactionOut(BaseModel):
    id: int
    title: str
    amount: float
    type: str
    category: str
    date: dt.date
    owner_id: int

    class Config:
        from_attributes = True
