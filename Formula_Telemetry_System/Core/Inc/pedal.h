#ifndef INC_PEDAL_H_
#define INC_PEDAL_H_

#include <stdint.h>
#include <stdbool.h>
#include "app_config.h"

void Pedal_Init(void);
uint16_t Pedal_FilterMovingAverage(uint16_t raw_sample, uint8_t channel);
uint8_t Pedal_Normalize(uint16_t raw_adc, bool is_inverted);

#endif /* INC_PEDAL_H_ */
