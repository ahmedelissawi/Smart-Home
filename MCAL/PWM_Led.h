#ifndef PWM_H
#define PWM_H

#include <stdint.h>

void BlueLED_Init(void);

void BlueLED_SetDutyCycle(uint8_t duty_cycle);

#endif 