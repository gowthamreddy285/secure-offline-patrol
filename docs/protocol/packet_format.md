# Packet Protocol Specification

> Version: 1.0 (Minimal Working Protocol)
> Full protocol will be designed in Phase 5.

## Overview

All communication between field nodes and the gateway uses a structured packet format.
Packets are transmitted over LoRa (SX1262) and must fit within the LoRa payload limit.

## Phase 4 — Minimal CSV Packet

For initial testing, packets use a simple CSV format:

```
NODE_ID,SEQUENCE,TIMESTAMP,VALUE
```

**Example:**
```
NODE01,1,1726412345,1234
```

| Field     | Type   | Size    | Description                     |
|-----------|--------|---------|---------------------------------|
| NODE_ID   | String | 6 chars | Node identifier (e.g., NODE01)  |
| SEQUENCE  | Uint16 | 1-65535 | Auto-incrementing per node      |
| TIMESTAMP | Uint32 | epoch   | Unix timestamp (seconds)        |
| VALUE     | Int32  | varies  | Sensor reading                  |

## Phase 5 — Structured Binary Protocol (Planned)

```
┌──────────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬───────┐
│ VERSION  │ TYPE │ NODE │ SEQ  │ TIME │ SENS │ VAL  │ FLAGS│ CRC16 │
│  1 byte  │1 byte│8 byte│2 byte│4 byte│1 byte│4 byte│1 byte│2 byte │
└──────────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴───────┘
Total: 24 bytes (fits within LoRa payload)
```

### Planned Fields

| Field          | Bytes | Description                                    |
|----------------|-------|------------------------------------------------|
| version        | 1     | Protocol version (currently 1)                 |
| packet_type    | 1     | TELEMETRY, PATROL, ALERT, ACK, HEARTBEAT       |
| node_id        | 8     | Node identifier (null-padded)                  |
| sequence       | 2     | Packet sequence number                         |
| timestamp      | 4     | Unix epoch timestamp                           |
| sensor_type    | 1     | INMP441, RFID, AUDIO_ML                        |
| sensor_value   | 4     | Sensor reading (signed 32-bit)                 |
| flags          | 1     | Bit flags (ACK requested, priority, etc.)      |
| crc16          | 2     | CRC-16 checksum for integrity                  |

### Future Extensions (appended after base packet)

| Extension      | Bytes | Phase | Description                      |
|----------------|-------|-------|----------------------------------|
| rssi           | 2     | 6     | Received signal strength (dBm)   |
| snr            | 1     | 6     | Signal-to-noise ratio (dB)       |
| previous_hash  | 32    | 13    | Hash chain link                  |
| signature      | 64    | 14    | ECC secp256r1 signature          |
| confidence     | 1     | 15    | ML classification confidence     |
| event_class    | 1     | 15    | ML event type                    |

## Packet Types

| Value | Name          | Description                           |
|-------|---------------|---------------------------------------|
| 0x01  | TELEMETRY     | Periodic sensor reading               |
| 0x02  | PATROL_EVENT  | RFID checkpoint scan                  |
| 0x03  | ALERT         | Acoustic anomaly detected             |
| 0x10  | ACK           | Acknowledgement from gateway          |
| 0x20  | HEARTBEAT     | Node alive signal                     |

## Design Rationale

- **Compact**: LoRa has ~250 byte payload limit at low data rates. Keep packets small.
- **Extensible**: Version field + flags allow future expansion.
- **Self-contained**: Each packet carries its own node ID and sequence number.
- **Offline-friendly**: Sequence numbers enable duplicate detection and ordering.

---

*This document will be expanded in Phase 5.*
