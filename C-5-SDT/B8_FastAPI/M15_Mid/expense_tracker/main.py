from fastapi import FastAPI

import models
from database import engine
from routers import auth, transactions

# Create all tables (users, transactions) if they don't already exist.
models.Base.metadata.create_all(bind=engine)

app = FastAPI(
    title="Personal Expense Tracker API",
    description="FastAPI + SQLAlchemy + PostgreSQL + JWT auth expense tracker (Phitron Module 16 Mid Term).",
    version="1.0.0",
)

app.include_router(auth.router)
app.include_router(transactions.router)


@app.get("/", tags=["Health"])
def health_check():
    return {"status": "ok", "message": "Expense Tracker API is running"}
