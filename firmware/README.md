# Firmware

This directory contains all ESP32-S3 firmware for the Secure Offline Patrol system.

## Structure

```
firmware/
├── sensor_node/          # Field node: reads sensors, builds packets, sends via LoRa
│   └── sensor_node.ino
├── lora_gateway/         # Gateway: receives LoRa packets, forwards to backend
│   └── lora_gateway.ino
└── common/
    └── protocol/         # Shared protocol definitions (packet format, constants)
        └── protocol.h
```

## Development Environment

- **IDE**: Arduino IDE 2.x
- **Board**: ESP32-S3 DevKit
- **Board Package**: `esp32` by Espressif (install via Board Manager)
  - URL: `https://espressif.github.io/arduino-esp32/package_esp32_index.json`

## Arduino IDE Setup

1. Open Arduino IDE
2. Go to **File → Preferences**
3. Add the ESP32 board manager URL above to "Additional Board Manager URLs"
4. Go to **Tools → Board → Board Manager**
5. Search for `esp32` and install the latest version
6. Select board: **ESP32S3 Dev Module**
7. Set USB CDC On Boot: **Enabled** (for Serial Monitor over USB)

## GPIO Pin Assignment

See [`../docs/hardware/gpio_pinout.md`](../docs/hardware/gpio_pinout.md) for the master GPIO assignment document.

## Build & Upload

1. Open the `.ino` file in Arduino IDE
2. Select the correct board and port
3. Click **Upload**
4. Open Serial Monitor at **115200** baud
