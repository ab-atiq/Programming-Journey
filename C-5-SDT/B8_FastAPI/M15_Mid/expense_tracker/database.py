import os
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base

# ---------------------------------------------------------------------------
# PostgreSQL connection URL.
#
# Set this via an environment variable so the SAME code works:
#   - locally               -> point to your local/online Postgres instance
#   - on Render             -> Render injects DATABASE_URL automatically
#                               when you attach a Postgres database
#
# Example (Supabase / Render Postgres / ElephantSQL, etc.):
#   postgresql://<user>:<password>@<host>:5432/<database>
# ---------------------------------------------------------------------------
SQLALCHEMY_DATABASE_URL = os.getenv(
    "DATABASE_URL",
    "postgresql://postgres:postgres@localhost:5432/expense_tracker",
)

# Render (and some providers) give a URL starting with "postgres://" which
# SQLAlchemy no longer accepts - normalize it to "postgresql://".
if SQLALCHEMY_DATABASE_URL.startswith("postgres://"):
    SQLALCHEMY_DATABASE_URL = SQLALCHEMY_DATABASE_URL.replace(
        "postgres://", "postgresql://", 1
    )

engine = create_engine(SQLALCHEMY_DATABASE_URL)

SessionLocal = sessionmaker(autoflush=False, autocommit=False, bind=engine)

Base = declarative_base()
