#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "PWM_Servo.h"
void CW(void)
{
//the servo rotates 30 degres in clockwise direction
//here the PWM fn must be used
Servo_Angle(30);

}
void CCW(void)
{
////the servo rotates 30 degres in counter clockwise direction
//here the PWM fn must be used
Servo_Angle(-30);

}