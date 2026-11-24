#include "telemetry.h"
#include <string.h>

TelemetryFrame_t tx_telemetry;
uint8_t tx_raw_buf[TELEMETRY_FRAME_SIZE];
static uint8_t heartbeat_cnt = 0;

void Telemetry_Init(void)
{
    memset(&tx_telemetry, 0, sizeof(TelemetryFrame_t));
    memset(tx_raw_buf, 0, sizeof(tx_raw_buf));
    heartbeat_cnt = 0;
}

uint8_t Telemetry_CalculateChecksum(const TelemetryFrame_t *frame)
{
    const uint8_t *ptr = (const uint8_t *)frame;
    uint8_t xor_val = 0;
    for (int i = 2; i <= 16; i++) {
        xor_val ^= ptr[i];
    }
    return xor_val;
}

void Telemetry_PrepareFrame(uint16_t rpm, uint8_t speed, uint8_t gear, uint8_t tps)
{
    tx_telemetry.header1 = TELEMETRY_HEADER_1;
    tx_telemetry.header2 = TELEMETRY_HEADER_2;

    // Big-Endian RPM dönüşümü
    tx_telemetry.rpm            = ((rpm >> 8) & 0xFFU) | ((rpm & 0xFFU) << 8);
    tx_telemetry.speed          = speed;
    tx_telemetry.coolant_temp   = 85U;
    tx_telemetry.oil_temp       = 90U;
    tx_telemetry.bat_voltage    = 1240U; // 12.40V
    tx_telemetry.gear           = gear;
    tx_telemetry.soc            = 85U;
    tx_telemetry.inverter_temp  = 48U;
    tx_telemetry.tps            = tps;
    tx_telemetry.brake_pressure = 0U;
    tx_telemetry.heartbeat      = heartbeat_cnt++;

    tx_telemetry.stop_byte1 = TELEMETRY_STOP_BYTE;
    tx_telemetry.stop_byte2 = TELEMETRY_STOP_BYTE;
    tx_telemetry.stop_byte3 = TELEMETRY_STOP_BYTE;

    tx_telemetry.checksum = Telemetry_CalculateChecksum(&tx_telemetry);

    memcpy(tx_raw_buf, &tx_telemetry, sizeof(TelemetryFrame_t));
}
