#include <stdio.h>
#include <stdint.h>
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "PORT.h"
#include "UART.h"
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"
#include "PLL.h"
#include "PWM_Led.h"
#include "PWM_Servo.h"
#include "servomotor.h"
uint8_t ADC_to_temp (int ADCval)
{
	 
	//momken n7ot delay 250ms lo 7abena
	
	//returns temp in degree celsius
	uint8_t tempValue;
	tempValue = (uint8_t)(147.5 - ((75.0 * 3.3 * (float)ADCval)) / 4096);
	return tempValue;
}


void SystemInit (void)
{
	

	PLL_Init();
UART_init(7);
	Servo_Init();
	ADC_Init(PE2,sensor);
	BlueLED_Init();

	
	

}


int main(void)
{
	/*
	uint32_t delay = 2000000;
	while (delay--);
	CW();*/
	
	while(1)
	{
		float x;
		uint8_t out, LED, servo, temp;
		
		//send
		x=ADC_u8GetResult();
		temp=ADC_to_temp (x);
		UART_write(7,temp);
		//recieve
		out=UART_Read(7);
		LED = out & 0x3F;
		servo = out & 0xC0;

			BlueLED_SetDutyCycle(LED*(1.587301587));
		
		if(servo==0x80)
		{
			//CCW
			CCW();
		}
		else if(servo==0x40)
		{
		//CW
			CW();
		}
		else if(servo==0xC0)
		{
			//do nothing
		}
}

	}
