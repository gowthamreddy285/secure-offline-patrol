# Backend — Secure Offline Patrol

FastAPI backend for receiving patrol telemetry, storing it, and serving dashboard data.

## Tech Stack

- **Framework**: FastAPI
- **Database**: SQLite (dev) → PostgreSQL (production)
- **ORM**: SQLAlchemy
- **Validation**: Pydantic

## Setup

```bash
cd backend
python -m venv venv

# Windows
venv\Scripts\activate

# Linux/Mac
source venv/bin/activate

pip install -r requirements.txt
```

## Run

```bash
uvicorn app.main:app --reload --host 0.0.0.0 --port 8000
```

## API Docs

Once running, visit:
- Swagger UI: http://localhost:8000/docs
- ReDoc: http://localhost:8000/redoc

## Endpoints (Planned)

| Method | Path              | Description               | Phase |
|--------|-------------------|---------------------------|-------|
| POST   | /api/telemetry    | Receive telemetry packet  | 7     |
| GET    | /api/telemetry    | List telemetry records    | 7     |
| GET    | /api/nodes        | List registered nodes     | 7     |
| GET    | /api/nodes/{id}   | Node status & latest data | 7     |

## Testing

```bash
# Health check
curl http://localhost:8000/

# Post telemetry (Phase 7)
curl -X POST http://localhost:8000/api/telemetry \
  -H "Content-Type: application/json" \
  -d '{"node_id":"NODE01","sequence":1,"timestamp":1726412345,"sensor":"INMP441","value":1234,"rssi":-67,"snr":8.5}'
```
