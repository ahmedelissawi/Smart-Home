#ifndef __PWM_H__
#define __PWM_H__

#include <stdint.h>

void BlueLED_Init(void);

void BlueLED_SetDutyCycle(uint8_t duty_cycle);

#endif // __PWM_H__