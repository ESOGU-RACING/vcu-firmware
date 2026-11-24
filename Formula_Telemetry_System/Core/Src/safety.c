#include "safety.h"

static uint32_t apps_fault_duration_ms = 0;

void Safety_Init(void)
{
    apps_fault_duration_ms = 0;
}

bool Safety_CheckSCSRange(uint16_t raw_apps1, uint16_t raw_apps2)
{
    // 3. Hafta: <0.1V ve >3.2V kablo kopması / kısa devre kontrolü eklenecek
    (void)raw_apps1;
    (void)raw_apps2;
    return true;
}

/**
 * @brief  T11.8 Plausibility kontrolü (1 ms periyotla çağrılır)
 * @retval true: Güvenli (Sürüş izni var), false: APPS Hatası (Güç kesilmeli)
 */
bool Safety_EvaluateT11_8(uint8_t apps1_pct, uint8_t apps2_pct)
{
    int16_t diff = (int16_t)apps1_pct - (int16_t)apps2_pct;
    if (diff < 0) {
        diff = -diff;
    }

    if (diff > (int16_t)APPS_MAX_DIFF_PCT) {
        apps_fault_duration_ms++;
        if (apps_fault_duration_ms >= APPS_FAULT_TIMEOUT_MS) {
            return false; // 100 ms doldu, Safe State tetikle
        }
    } else {
        apps_fault_duration_ms = 0;
    }

    return true;
}
