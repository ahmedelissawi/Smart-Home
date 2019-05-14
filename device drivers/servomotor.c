#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
void CW(void)
{
//the servo rotates 30 degres in clockwise direction
//here the PWM fn must be used
Servo_SetDutyCycle(uint8_t duty_cycle);

}
void CCW(void)
{
////the servo rotates 30 degres in clockwise direction
//here the PWM fn must be used
Servo_SetDutyCycle(uint8_t duty_cycle);
}