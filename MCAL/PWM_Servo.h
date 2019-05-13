#ifndef PWM_H
#define PWM_H

#include <stdint.h>

void Servo_Init(void);

void Servo_SetDutyCycle(uint8_t duty_cycle);

#endif // PWM_H