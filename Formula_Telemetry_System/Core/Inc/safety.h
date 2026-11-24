#ifndef INC_SAFETY_H_
#define INC_SAFETY_H_

#include <stdint.h>
#include <stdbool.h>
#include "app_config.h"

void Safety_Init(void);
bool Safety_CheckSCSRange(uint16_t raw_apps1, uint16_t raw_apps2);
bool Safety_EvaluateT11_8(uint8_t apps1_pct, uint8_t apps2_pct);

#endif /* INC_SAFETY_H_ */
