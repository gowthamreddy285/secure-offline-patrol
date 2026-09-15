# System Architecture

## High-Level Overview

```
┌─────────────────────────────────────────────────────────┐
│                    FOREST (OFFLINE)                      │
│                                                          │
│  ┌──────────────────────────────────┐                    │
│  │        FIELD NODE (ESP32-S3)     │                    │
│  │                                  │                    │
│  │  INMP441 ──► Audio Processing   │                    │
│  │               │                  │                    │
│  │  RFID ──────► Checkpoint Scan   │                    │
│  │               │                  │                    │
│  │  R307S ─────► Auth (future)     │                    │
│  │               │                  │                    │
│  │          Event Generation        │                    │
│  │               │                  │                    │
│  │       Hash Chain + ECC Sign      │                    │
│  │               │                  │                    │
│  │        Offline Storage           │                    │
│  │               │                  │                    │
│  │           SX1262 LoRa TX         │                    │
│  └───────────────┬──────────────────┘                    │
│                  │ LoRa (433/868/915 MHz)                 │
│                  ▼                                        │
│  ┌──────────────────────────────────┐                    │
│  │        LORA GATEWAY              │                    │
│  │                                  │                    │
│  │  SX1262 LoRa RX                 │                    │
│  │       │                          │                    │
│  │  Packet Validation               │                    │
│  │  Duplicate Detection             │                    │
│  │  ACK Transmission                │                    │
│  │  Local Buffer (offline)          │                    │
│  │       │                          │                    │
│  │  Wi-Fi / GSM (when available)    │                    │
│  └───────┬──────────────────────────┘                    │
└──────────┼───────────────────────────────────────────────┘
           │ Internet (intermittent)
           ▼
┌─────────────────────────────────────────────────────────┐
│                  BACKEND (CLOUD / SERVER)                 │
│                                                          │
│  ┌──────────────────┐   ┌──────────────────┐            │
│  │   FastAPI         │──►│  PostgreSQL      │            │
│  │                   │   │                  │            │
│  │  POST /telemetry  │   │  telemetry table │            │
│  │  GET  /nodes      │   │  nodes table     │            │
│  │  GET  /events     │   │  events table    │            │
│  │  Sig verification │   │  hash_chain      │            │
│  └──────────────────┘   └──────────────────┘            │
│           │                                              │
│           ▼                                              │
│  ┌──────────────────┐                                    │
│  │  React Dashboard  │                                   │
│  │                   │                                   │
│  │  Node status      │                                   │
│  │  Live graphs      │                                   │
│  │  Alert feed       │                                   │
│  │  Patrol timeline  │                                   │
│  └──────────────────┘                                    │
└─────────────────────────────────────────────────────────┘
```

## Data Flow

1. **Sensor → ESP32-S3**: INMP441 feeds audio via I2S. RFID scanned via SPI.
2. **ESP32-S3 → Processing**: Event classification, hash chaining, ECC signing.
3. **ESP32-S3 → SX1262**: Compact packet transmitted via LoRa.
4. **SX1262 → Gateway**: LoRa reception, validation, ACK.
5. **Gateway → Backend**: HTTP POST when internet is available.
6. **Backend → Database**: Telemetry stored, signatures verified.
7. **Backend → Dashboard**: REST API serves real-time data.

## Offline Behavior

- Field nodes **never** require internet.
- Gateway buffers packets locally during outages.
- Sync happens automatically when connectivity returns.
- Duplicate detection prevents double-insertion.
