#include "simulation.h"

void Simulation_Init(SimVehicleState_t *state)
{
    state->speed = 0;
    state->rpm   = 0;
    state->tps   = 0;
    state->gear  = 0;
}

void Simulation_Step(SimVehicleState_t *state)
{
    state->speed++;
    if (state->speed >= SIM_SPEED_MAX) {
        state->speed = 0;
    }

    if (state->speed == 0) {
        state->gear = 0;
        state->rpm  = 0;
    } else if (state->speed < 30) {
        state->gear = 1;
        state->rpm  = (uint16_t)(((uint32_t)state->speed * RPM_MAX) / 29U);
    } else if (state->speed < 60) {
        state->gear = 2;
        state->rpm  = RPM_AFTER_SHIFT +
                      (uint16_t)(((uint32_t)(state->speed - 30U) *
                                  (RPM_MAX - RPM_AFTER_SHIFT)) / 29U);
    } else if (state->speed < 90) {
        state->gear = 3;
        state->rpm  = RPM_AFTER_SHIFT +
                      (uint16_t)(((uint32_t)(state->speed - 60U) *
                                  (RPM_MAX - RPM_AFTER_SHIFT)) / 29U);
    } else {
        state->gear = 4;
        state->rpm  = RPM_AFTER_SHIFT +
                      (uint16_t)(((uint32_t)(state->speed - 90U) *
                                  (RPM_MAX - RPM_AFTER_SHIFT)) / 29U);
    }

    state->tps = (uint8_t)((state->speed * 100U) / SIM_SPEED_MAX);
}
