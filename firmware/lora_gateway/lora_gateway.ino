/*
 * =============================================================
 * Secure Offline Patrol — LoRa Gateway Firmware
 * =============================================================
 * 
 * Board  : ESP32-S3 DevKit (or Raspberry Pi with SX1262 HAT)
 * Module : SX1262 (LoRa)
 * 
 * This is a placeholder for Phase 6+.
 * The gateway receives LoRa packets from field nodes,
 * decodes them, and forwards to the FastAPI backend.
 * 
 * =============================================================
 */

void setup() {
    Serial.begin(115200);
    while (!Serial) { delay(10); }
    
    Serial.println("=================================");
    Serial.println("Secure Offline Patrol — LoRa Gateway");
    Serial.println("Phase 1: Project structure created");
    Serial.println("=================================");
    Serial.println();
    Serial.println("Next steps:");
    Serial.println("  Phase 6 — LoRa gateway receive & decode");
    Serial.println("  Phase 8 — Gateway → FastAPI sync");
    Serial.println("  Phase 10 — Offline buffering");
}

void loop() {
    // Will be implemented in subsequent phases
    delay(1000);
}
