#include "pedal.h"

void Pedal_Init(void)
{
    // 4. Hafta: Moving Average tamponları burada sıfırlanacak
}

uint16_t Pedal_FilterMovingAverage(uint16_t raw_sample, uint8_t channel)
{
    // 4. Hafta: 8-10 örneklik hareketli ortalama eklenecek (Şimdilik ham değer döner)
    (void)channel;
    return raw_sample;
}

uint8_t Pedal_Normalize(uint16_t raw_adc, bool is_inverted)
{
    if (raw_adc < PEDAL_ADC_MIN_RAW || raw_adc > PEDAL_ADC_MAX_RAW) {
        return 0U;
    }

    uint32_t span = PEDAL_ADC_MAX_RAW - PEDAL_ADC_MIN_RAW;
    if (!is_inverted) {
        return (uint8_t)(((uint32_t)(raw_adc - PEDAL_ADC_MIN_RAW) * 100U) / span);
    } else {
        return (uint8_t)(((uint32_t)(PEDAL_ADC_MAX_RAW - raw_adc) * 100U) / span);
    }
}
