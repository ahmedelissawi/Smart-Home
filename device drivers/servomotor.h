#ifndef servo_H_
#define servo_H_

typedef unsigned char unit8;
#include <PWM_Servo.h>
void Servo_Init(void);
//the servo rotates 30 degres in clockwise direction
void CW(void);

////the servo rotates 30 degres in counter clockwise direction
void CCW(void);


#endif