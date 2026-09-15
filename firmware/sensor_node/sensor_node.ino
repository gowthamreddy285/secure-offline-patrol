/*
 * =============================================================
 * Secure Offline Patrol — Sensor Node Firmware
 * =============================================================
 * 
 * Board  : ESP32-S3 DevKit
 * Sensors: INMP441 (microphone), SX1262 (LoRa)
 * 
 * This is a placeholder for Phase 2+.
 * Phase 2: INMP441 sensor reading test
 * Phase 3: SX1262 LoRa transmission test
 * Phase 4: Combined sensor + LoRa
 * 
 * =============================================================
 */

void setup() {
    Serial.begin(115200);
    while (!Serial) { delay(10); }
    
    Serial.println("=================================");
    Serial.println("Secure Offline Patrol — Sensor Node");
    Serial.println("Phase 1: Project structure created");
    Serial.println("=================================");
    Serial.println();
    Serial.println("Next steps:");
    Serial.println("  Phase 2 — INMP441 microphone test");
    Serial.println("  Phase 3 — SX1262 LoRa test");
    Serial.println("  Phase 4 — Sensor + LoRa integration");
}

void loop() {
    // Will be implemented in subsequent phases
    delay(1000);
}
