#ifndef INC_SIMULATION_H_
#define INC_SIMULATION_H_

#include <stdint.h>
#include "app_config.h"

typedef struct {
    uint16_t speed;
    uint16_t rpm;
    uint8_t  tps;
    uint8_t  gear;
} SimVehicleState_t;

void Simulation_Init(SimVehicleState_t *state);
void Simulation_Step(SimVehicleState_t *state);

#endif /* INC_SIMULATION_H_ */
