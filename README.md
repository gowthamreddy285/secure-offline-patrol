# Secure Offline Patrol Verification Framework

> **Final Year Project** — Secure Offline Patrol Verification Framework for Forest Areas with Limited Connectivity

## Overview

This system enables **tamper-proof, offline-capable patrol verification** in remote forest areas with limited or no internet connectivity. Field nodes collect sensor data and patrol events, secure them with hash-chained ledgers and digital signatures, and transmit compact packets over **LoRa** to a gateway that synchronizes with the backend when connectivity is available.

## Architecture

```
FOREST FIELD NODE
      │
      │ Sensor data / Patrol events
      ▼
   ESP32-S3
      │
      │ LoRa (SX1262)
      ▼
   LoRa Gateway
      │
      │ Wi-Fi / GSM (when available)
      ▼
   FastAPI Backend
      │
      ▼
   PostgreSQL
      │
      ▼
   React Dashboard
```

## Key Principles

- **Offline-first**: Field nodes operate without internet. Only the gateway needs connectivity (intermittently).
- **Tamper-proof**: Hash-chained ledger + ECC digital signatures prevent log tampering.
- **Low bandwidth**: LoRa carries only compact structured packets — no raw audio or images.
- **Modular**: Each subsystem (sensor node, gateway, backend, dashboard) is independently developed and tested.

## Team

| Member    | Responsibility                                        |
|-----------|-------------------------------------------------------|
| Gowtham   | RFID checkpoint firmware, hash-chained ledger, digital signing |
| Tejeswar  | TinyML acoustic classifier, two-stage wake pipeline   |
| Kireeti   | LoRa gateway firmware, backend sync, packet verification |
| Abhiram   | FastAPI backend, PostgreSQL, dashboard, testing        |

## Repository Structure

```
secure-offline-patrol/
├── firmware/
│   ├── sensor_node/          # ESP32-S3 field node firmware
│   ├── lora_gateway/         # LoRa gateway firmware
│   └── common/
│       └── protocol/         # Shared packet protocol definitions
├── backend/
│   └── app/                  # FastAPI application
├── dashboard/
│   ├── src/                  # React frontend source
│   └── public/               # Static assets
├── docs/
│   ├── architecture/         # System architecture diagrams
│   ├── hardware/             # Wiring guides, GPIO maps, BOM
│   └── protocol/             # Packet format specifications
├── data/
│   └── sample_packets/       # Example packets for testing
├── .gitignore
└── README.md
```

## Development Phases

| Phase | Description                        | Status      |
|-------|------------------------------------|-------------|
| 1     | Repository & project structure     | ✅ Complete  |
| 2     | INMP441 sensor test                | ⬜ Planned   |
| 3     | SX1262 LoRa test                   | ⬜ Planned   |
| 4     | Sensor + LoRa integration          | ⬜ Planned   |
| 5     | Packet protocol design             | ⬜ Planned   |
| 6     | LoRa gateway                       | ⬜ Planned   |
| 7     | FastAPI backend                    | ⬜ Planned   |
| 8     | Gateway → backend sync             | ⬜ Planned   |
| 9     | React dashboard                    | ⬜ Planned   |
| 10    | Offline storage & buffering        | ⬜ Planned   |
| 11    | ACK & retransmission               | ⬜ Planned   |
| 12    | RFID integration                   | ⬜ Planned   |
| 13    | Hash-chained ledger                | ⬜ Planned   |
| 14    | ECC digital signing                | ⬜ Planned   |
| 15    | TinyML acoustic classifier         | ⬜ Planned   |

## Hardware (Field Node)

- ESP32-S3 DevKit
- INMP441 MEMS microphone
- SX1262 LoRa module
- RFID module (later)
- R307S fingerprint sensor (later)
- RTC module (later)

## Hardware (Gateway)

- SX1262 LoRa module
- Raspberry Pi / PC
- Wi-Fi or GSM connectivity

## Getting Started

### Firmware (Arduino IDE)
See [`firmware/README.md`](firmware/README.md)

### Backend
See [`backend/README.md`](backend/README.md)

### Dashboard
See [`dashboard/README.md`](dashboard/README.md)

## License

This project is part of a final-year academic submission. All rights reserved.
