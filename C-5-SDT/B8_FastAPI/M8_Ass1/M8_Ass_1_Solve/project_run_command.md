# Create a virtual environment (If you want to check project in your local machine in separate environment)

### For Windows

```PowerShell

python -m venv venv
```

### For Linux or MacOS

```bash
python3 -m venv venv
```

## Activate the virtual environment

### For Windows

PowerShell

```bash
venv\Scripts\activate
```

Bash

```bash
source venv/Scripts/activate
```

### For Linux or MacOS

```bash
source venv/bin/activate
```

# Install the required dependencies

```bash
pip install -r requirements.txt
```

# Run the FastAPI application

```bash
uvicorn main:app --reload
```

# Open your web browser and go to

```bash
http://localhost:8000
```

or,

```bash
http://localhost:8000/docs
```

or,

```bash
http://127.0.0.1:8000
```

or,

```bash
http://127.0.0.1:8000/docs
```

# Deactivate the virtual environment (If you want to exit from the virtual environment)

### For Windows

```bash
deactivate
```

### For Linux or MacOS

```bash
deactivate
```
