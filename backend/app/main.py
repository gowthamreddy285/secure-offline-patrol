"""
Secure Offline Patrol — FastAPI Application Entry Point

Run with:
    uvicorn app.main:app --reload --host 0.0.0.0 --port 8000
"""

from fastapi import FastAPI

app = FastAPI(
    title="Secure Offline Patrol API",
    description="Backend for the Secure Offline Patrol Verification Framework",
    version="0.1.0",
)


@app.get("/")
async def root():
    return {
        "project": "Secure Offline Patrol Verification Framework",
        "status": "Phase 1 — Project structure created",
        "next": "Phase 7 — Full API implementation",
    }
