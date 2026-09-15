# Bill of Materials (BOM)

## Field Node (per unit)

| # | Component          | Qty | Specification                     | Notes                       |
|---|-------------------|-----|-----------------------------------|-----------------------------|
| 1 | ESP32-S3 DevKit   | 1   | Dual-core, 2.4GHz, USB-C         | Main MCU                    |
| 2 | INMP441           | 1   | I2S MEMS microphone               | Acoustic sensor             |
| 3 | SX1262 LoRa       | 1   | 433/868/915 MHz, SPI interface    | Long-range communication    |
| 4 | RFID Reader       | 1   | MFRC522 or compatible, SPI        | Checkpoint scanning (Ph 12) |
| 5 | R307S Fingerprint | 1   | UART interface, optical sensor    | Auth (Phase 14)             |
| 6 | RTC Module        | 1   | DS3231 or similar, I2C            | Accurate timestamps         |
| 7 | Breadboard        | 1   | Full-size                         | Prototyping                 |
| 8 | Jumper Wires      | ~20 | Male-to-male, male-to-female      | Connections                 |
| 9 | USB-C Cable       | 1   | Data-capable                      | Programming + power         |

## Gateway

| # | Component          | Qty | Specification                     | Notes                       |
|---|-------------------|-----|-----------------------------------|-----------------------------|
| 1 | Raspberry Pi      | 1   | Pi 4 or Pi 3B+ (or PC)           | Gateway host                |
| 2 | SX1262 LoRa       | 1   | Matching frequency with nodes     | LoRa reception              |
| 3 | Wi-Fi / GSM       | 1   | Built-in Wi-Fi or GSM module      | Internet uplink             |

## Phase 2 Requirements (First Test)

Only these are needed to start:

- ESP32-S3 DevKit × 1
- INMP441 microphone × 1
- Breadboard × 1
- Jumper wires × 5
- USB-C cable × 1
