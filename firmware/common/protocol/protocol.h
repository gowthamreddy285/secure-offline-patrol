/*
 * =============================================================
 * Secure Offline Patrol — Shared Packet Protocol
 * =============================================================
 * 
 * This header defines the packet format shared between
 * sensor nodes and the LoRa gateway.
 * 
 * PROTOCOL VERSION: 1 (minimal working protocol)
 * 
 * Full protocol specification:
 *   docs/protocol/packet_format.md
 * 
 * =============================================================
 */

#ifndef PATROL_PROTOCOL_H
#define PATROL_PROTOCOL_H

#include <stdint.h>

// -----------------------------------------------------------
// Protocol constants
// -----------------------------------------------------------

#define PROTOCOL_VERSION     1
#define MAX_NODE_ID_LEN      8
#define MAX_PACKET_SIZE      64   // LoRa payload limit for reliability
#define PACKET_DELIMITER     ','

// -----------------------------------------------------------
// Packet types (will be expanded in later phases)
// -----------------------------------------------------------

typedef enum {
    PKT_TELEMETRY   = 0x01,   // Sensor telemetry data
    PKT_PATROL_EVENT = 0x02,  // RFID checkpoint event (Phase 12)
    PKT_ALERT       = 0x03,   // Acoustic alert (Phase 15)
    PKT_ACK         = 0x10,   // Acknowledgement (Phase 11)
    PKT_HEARTBEAT   = 0x20,   // Node alive heartbeat
} packet_type_t;

// -----------------------------------------------------------
// Sensor types
// -----------------------------------------------------------

typedef enum {
    SENSOR_INMP441  = 0x01,   // MEMS microphone
    SENSOR_RFID     = 0x02,   // RFID reader (Phase 12)
    SENSOR_AUDIO_ML = 0x03,   // TinyML classification (Phase 15)
} sensor_type_t;

// -----------------------------------------------------------
// Minimal telemetry packet (Phase 4 format)
// -----------------------------------------------------------
// CSV format: NODE_ID,SEQ,TIMESTAMP,VALUE
// Example:    NODE01,1,1726412345,1234
//
// This will be replaced with a binary/structured format
// in Phase 5 (protocol design).
// -----------------------------------------------------------

typedef struct {
    char        node_id[MAX_NODE_ID_LEN + 1];
    uint16_t    sequence;
    uint32_t    timestamp;
    uint8_t     packet_type;
    uint8_t     sensor_type;
    int32_t     sensor_value;
    // Future fields (Phase 5+):
    // int16_t  rssi;
    // int8_t   snr;
    // uint8_t  flags;
    // uint8_t  hash[32];
    // uint8_t  signature[64];
} patrol_packet_t;

#endif // PATROL_PROTOCOL_H
