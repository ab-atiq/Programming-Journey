# Personal Expense Tracker API

FastAPI + SQLAlchemy + PostgreSQL + JWT Authentication.
Built for Phitron Module 16 — Mid Term.

Users register, log in, and manage **their own** income/expense transactions.
Every transaction route is protected by JWT, and a user can only ever see or
modify transactions they own.

## Folder Structure

```
expense_tracker/
├── main.py                    # FastAPI app, includes routers, creates tables
├── database.py                # SQLAlchemy engine / session (reads DATABASE_URL)
├── models.py                  # Users, Transactions ORM models
├── schemas.py                 # Pydantic request/response schemas
├── requirements.txt
├── Procfile                   # Render start command
├── .env.example
├── .gitignore
├── routers/
│   ├── __init__.py
│   ├── auth.py                 # /auth/register, /auth/login, get_current_user
│   └── transactions.py         # /transactions CRUD + /transactions/filter
└── test/
    ├── __init__.py
    ├── test_main.py             # shared TestClient
    └── test_transactions.py     # 5+ pytest test cases
```

## Endpoints

| Method | Path                     | Auth | Description                          |
|--------|--------------------------|------|---------------------------------------|
| POST   | `/auth/register`         | No   | Register a new user                   |
| POST   | `/auth/login`            | No   | Login, returns JWT access token       |
| POST   | `/transactions`          | Yes  | Create a transaction                  |
| GET    | `/transactions`          | Yes  | Get all of the current user's transactions |
| GET    | `/transactions/filter`   | Yes  | Filter by type / category / amount range |
| GET    | `/transactions/{id}`     | Yes  | Get a single transaction               |
| PUT    | `/transactions/{id}`     | Yes  | Update a transaction                   |
| DELETE | `/transactions/{id}`     | Yes  | Delete a transaction                   |

`/transactions/filter` accepts query params: `type`, `category`,
`minimum_amount`, `maximum_amount` — all optional, combinable, e.g.:

```
GET /transactions/filter?type=expense&category=Food&minimum_amount=100&maximum_amount=5000
```

## Local Setup

1. **Create & activate a virtual environment**
   ```bash
   python -m venv venv
   source venv/bin/activate      # Windows: venv\Scripts\activate
   ```

2. **Install dependencies**
   ```bash
   pip install -r requirements.txt
   ```

3. **Set your database URL**
   Copy `.env.example` to `.env` (or export the variable directly) and point
   `DATABASE_URL` at an online PostgreSQL instance (Supabase, Render Postgres,
   Neon, ElephantSQL, etc.):
   ```bash
   export DATABASE_URL="postgresql://<user>:<password>@<host>:5432/<database>"
   export SECRET_KEY="a-long-random-string"
   ```
   Tables are created automatically on startup (`models.Base.metadata.create_all`).

4. **Run the server**
   ```bash
   uvicorn main:app --reload
   ```
   Open the interactive docs at `http://127.0.0.1:8000/docs`.

5. **Try it**
   - `POST /auth/register` → create a user
   - `POST /auth/login` (form-urlencoded `username` + `password`) → get `access_token`
   - Click "Authorize" in Swagger UI (or send `Authorization: Bearer <token>`)
     and call the `/transactions` endpoints.

   A ready-to-import Postman collection is provided separately for manual
   testing, with `{{base_url}}` and auto-saved `{{access_token}}` /
   `{{transaction_id}}` variables.

## Running Tests

```bash
pytest -v
```

`test/test_transactions.py` overrides `get_current_user` so tests don't need
a real JWT, and seeds/cleans up its own rows (ids `7777`, `8888`, `9999`) so
it's safe to run against your real database. It covers:

1. Get all transactions
2. Get a specific transaction (found + not found)
3. Create a transaction (valid + invalid amount)
4. Update a transaction (found + not found)
5. Delete a transaction (found + not found)

## Deploying to Render

1. Push this project to a GitHub repository.
2. On [Render](https://render.com): **New +** → **Web Service** → connect the repo.
3. Build command: `pip install -r requirements.txt`
4. Start command: `uvicorn main:app --host 0.0.0.0 --port $PORT` (already in `Procfile`)
5. Add environment variables in the Render dashboard:
   - `DATABASE_URL` — your online PostgreSQL connection string
   - `SECRET_KEY` — a random secret for JWT signing
6. Deploy. Your live docs will be at `https://<your-app>.onrender.com/docs`.

## Security Notes

- Passwords are hashed with **bcrypt** (via `passlib`) before being stored —
  the raw password is never saved, and `hashed_password` is never returned
  in any API response.
- JWTs are signed with `HS256` and expire after 30 minutes.
- Every `/transactions/*` route depends on `get_current_user`, which decodes
  and validates the JWT; all queries are additionally filtered by
  `owner_id == current_user.id`, so one user can never read/update/delete
  another user's data.
