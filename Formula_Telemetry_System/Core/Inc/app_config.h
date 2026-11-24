#ifndef INC_APP_CONFIG_H_
#define INC_APP_CONFIG_H_

#include <stdint.h>

/* T11.8 & Pedal Kalibrasyon Sabitleri */
#define APPS_MAX_DIFF_PCT           10U     // T11.8 Kuralı: Maksimum %10 Sapma
#define APPS_FAULT_TIMEOUT_MS       100U    // T11.8 Kuralı: 100 ms Zaman Aşımı
#define PEDAL_ADC_MIN_RAW           500U    // %0 Gaz Ham ADC Değeri
#define PEDAL_ADC_MAX_RAW           4000U   // %100 Gaz Ham ADC Değeri
#define SCS_ADC_MIN_LIMIT           124U    // <0.1V Kablo Kopması Sınırı (3. Hafta)
#define SCS_ADC_MAX_LIMIT           3971U   // >3.2V Kısa Devre Sınırı (3. Hafta)
#define PEDAL_MOVING_AVG_LEN        8U      // Hareketli Ortalama Penceresi (4. Hafta)

/* Simülasyon Sabitleri */
#define RPM_MAX                     8000U
#define RPM_AFTER_SHIFT             3000U
#define SIM_SPEED_MAX               120U

/* ICD Telemetri Paketi Sabitleri */
#define TELEMETRY_FRAME_SIZE        21U
#define TELEMETRY_HEADER_1          0x5AU
#define TELEMETRY_HEADER_2          0xA5U
#define TELEMETRY_STOP_BYTE         0xFFU
#define TELEMETRY_PERIOD_MS         50U

/* Hata Kodları */
#define ERR_NONE                    0x00U
#define ERR_APPS_PLAUSIBILITY       0x01U
#define ERR_SCS_OUT_OF_RANGE        0x02U

#endif /* INC_APP_CONFIG_H_ */
