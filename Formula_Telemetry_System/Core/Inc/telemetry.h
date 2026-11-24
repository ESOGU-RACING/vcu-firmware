#ifndef INC_TELEMETRY_H_
#define INC_TELEMETRY_H_

#include <stdint.h>
#include "app_config.h"

// 21 Baytlık ICD Telemetri Paketi (Nextion ve Canlı Veri Uyumlu)
typedef struct __attribute__((packed)) {
    uint8_t  header1;        // Byte 0    : 0x5A
    uint8_t  header2;        // Byte 1    : 0xA5
    uint16_t rpm;            // Byte 2-3  : Motor Devri (Big-Endian)
    uint8_t  speed;          // Byte 4    : Araç Hızı (km/h)
    uint8_t  coolant_temp;   // Byte 5    : Motor Sıcaklığı (°C)
    uint8_t  oil_temp;       // Byte 6    : Yağ Sıcaklığı (°C)
    uint16_t bat_voltage;    // Byte 7-8  : Akü Voltajı x 100 (Örn: 1240 = 12.40V)
    uint8_t  gear;           // Byte 9    : Vites (0: Boş, 1-6)
    uint8_t  soc;            // Byte 10   : Batarya Şarj % (0-100)
    uint8_t  inverter_temp;  // Byte 11   : Sürücü Sıcaklığı (°C)
    uint8_t  tps;            // Byte 12   : Gaz Pedalı % (APPS Çıktısı 0-100)
    uint16_t brake_pressure; // Byte 13-14: Fren Basıncı x 10 (Örn: 500 = 50.0 Bar)
    uint8_t  error_code;     // Byte 15   : Hata Kodu (Bit 0: APPS Tutarsızlığı)
    uint8_t  heartbeat;      // Byte 16   : Canlılık Sayacı (0-255)
    uint8_t  checksum;       // Byte 17   : Byte 2-16 XOR Mührü
    uint8_t  stop_byte1;     // Byte 18   : 0xFF (Nextion Bitiş 1)
    uint8_t  stop_byte2;     // Byte 19   : 0xFF (Nextion Bitiş 2)
    uint8_t  stop_byte3;     // Byte 20   : 0xFF (Nextion Bitiş 3)
} TelemetryFrame_t;

extern TelemetryFrame_t tx_telemetry;
extern uint8_t tx_raw_buf[TELEMETRY_FRAME_SIZE];

void Telemetry_Init(void);
uint8_t Telemetry_CalculateChecksum(const TelemetryFrame_t *frame);
void Telemetry_PrepareFrame(uint16_t rpm, uint8_t speed, uint8_t gear, uint8_t tps);

#endif /* INC_TELEMETRY_H_ */
