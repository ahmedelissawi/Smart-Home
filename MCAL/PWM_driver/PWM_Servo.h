#ifndef PWM_Servo_H
#define PWM_Servo_H

#include <stdint.h>

void Servo_Init(void);

void Servo_Angle(int8_t duty_cycle);

#endif