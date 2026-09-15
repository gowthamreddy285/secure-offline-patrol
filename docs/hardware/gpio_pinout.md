# ESP32-S3 GPIO Pin Assignment — Master Document

> ⚠️ **This is the single source of truth for all GPIO assignments.**
> Update this document whenever a new peripheral is added.
> Check this document BEFORE assigning any GPIO to avoid conflicts.

## Board: ESP32-S3 DevKit

---

## INMP441 (I2S MEMS Microphone) — Phase 2

| INMP441 Pin | ESP32-S3 GPIO | Notes                          |
|-------------|---------------|--------------------------------|
| VDD         | 3.3V          | Power supply                   |
| GND         | GND           | Ground                         |
| SD          | GPIO 15       | I2S Serial Data (DOUT)         |
| WS          | GPIO 16       | I2S Word Select (LRCLK)       |
| SCK         | GPIO 17       | I2S Serial Clock (BCLK)       |
| L/R         | GND           | Left channel (connect to GND)  |

**I2S Port**: I2S_NUM_0

---

## SX1262 LoRa Module (SPI) — Phase 3

| SX1262 Pin  | ESP32-S3 GPIO | Notes                          |
|-------------|---------------|--------------------------------|
| VCC         | 3.3V          | Power supply (3.3V only!)      |
| GND         | GND           | Ground                         |
| MOSI        | GPIO 11       | SPI Master Out Slave In        |
| MISO        | GPIO 13       | SPI Master In Slave Out        |
| SCK         | GPIO 12       | SPI Clock                      |
| NSS / CS    | GPIO 10       | SPI Chip Select                |
| RESET       | GPIO 9        | Module reset                   |
| DIO1        | GPIO 14       | Interrupt (TX/RX done)         |
| BUSY        | GPIO 8        | Module busy indicator          |

**SPI Bus**: HSPI (SPI2)

---

## RFID Module (SPI) — Phase 12

| RFID Pin    | ESP32-S3 GPIO | Notes                          |
|-------------|---------------|--------------------------------|
| VCC         | 3.3V          | Power supply                   |
| GND         | GND           | Ground                         |
| MOSI        | GPIO 11       | Shared SPI bus with SX1262     |
| MISO        | GPIO 13       | Shared SPI bus with SX1262     |
| SCK         | GPIO 12       | Shared SPI bus with SX1262     |
| SDA / CS    | GPIO 21       | RFID chip select (separate!)   |
| RST         | GPIO 47       | RFID reset                     |

> **Note**: RFID shares MOSI/MISO/SCK with SX1262 but uses a **separate CS pin**.
> Only one device communicates at a time via CS line.

---

## R307S Fingerprint Sensor (UART) — Phase 14

| R307S Pin   | ESP32-S3 GPIO | Notes                          |
|-------------|---------------|--------------------------------|
| VCC         | 3.3V or 5V    | Check module voltage           |
| GND         | GND           | Ground                         |
| TX          | GPIO 18       | UART RX on ESP32 side          |
| RX          | GPIO 5        | UART TX on ESP32 side          |

**UART Port**: Serial1

---

## RTC Module (I2C) — Future

| RTC Pin     | ESP32-S3 GPIO | Notes                          |
|-------------|---------------|--------------------------------|
| VCC         | 3.3V          | Power supply                   |
| GND         | GND           | Ground                         |
| SDA         | GPIO 6        | I2C Data                       |
| SCL         | GPIO 7        | I2C Clock                      |

---

## GPIO Summary

| GPIO | Function        | Peripheral   | Bus/Protocol |
|------|-----------------|--------------|--------------|
| 5    | UART TX         | R307S FP     | UART         |
| 6    | I2C SDA         | RTC          | I2C          |
| 7    | I2C SCL         | RTC          | I2C          |
| 8    | BUSY            | SX1262       | Digital      |
| 9    | RESET           | SX1262       | Digital      |
| 10   | SPI CS          | SX1262       | SPI          |
| 11   | SPI MOSI        | SX1262/RFID  | SPI (shared) |
| 12   | SPI SCK         | SX1262/RFID  | SPI (shared) |
| 13   | SPI MISO        | SX1262/RFID  | SPI (shared) |
| 14   | DIO1 (IRQ)      | SX1262       | Digital      |
| 15   | I2S SD (Data)   | INMP441      | I2S          |
| 16   | I2S WS (LRCLK)  | INMP441      | I2S          |
| 17   | I2S SCK (BCLK)  | INMP441      | I2S          |
| 18   | UART RX         | R307S FP     | UART         |
| 21   | SPI CS          | RFID         | SPI          |
| 47   | RESET           | RFID         | Digital      |

## Reserved / Avoid

| GPIO | Reason                                           |
|------|--------------------------------------------------|
| 0    | Boot mode / strapping pin                        |
| 3    | JTAG                                             |
| 19   | USB D- (if USB OTG used)                         |
| 20   | USB D+ (if USB OTG used)                         |
| 43   | UART0 TX (default Serial)                        |
| 44   | UART0 RX (default Serial)                        |

---

*Last updated: Phase 1 — Initial assignment*
