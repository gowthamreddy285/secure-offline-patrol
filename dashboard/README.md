# Dashboard — Secure Offline Patrol

React-based dashboard for visualizing patrol telemetry and node status.

## Tech Stack

- **Framework**: React (via Vite)
- **Charting**: Chart.js / Recharts
- **HTTP**: Axios / Fetch API

## Setup (Phase 9)

```bash
cd dashboard
npm install
npm run dev
```

## Features (Planned)

- Node status overview (online/offline)
- Latest sensor values
- RSSI and SNR indicators
- Live/near-live sensor graph
- Patrol event log
- Alert notifications

## Architecture

```
FastAPI Backend
      │
      │ REST API
      ▼
React Dashboard
```

The dashboard fetches data from the FastAPI backend.
It does NOT communicate directly with LoRa or field nodes.
