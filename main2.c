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

void SystemInit (void)
{
	//push buttons initialization
	Port_Init(PORTF);
	Port_SetPinDirection (PORTF, Pin0_mask ,Input);
	Port_SetPinDirection (PORTF, Pin4_mask ,Input);
	Port_SetPinPullUp(PORTF,Pin0_mask,1);
	Port_SetPinPullUp(PORTF,Pin4_mask,1);

	
	PLL_Init();
	UART_init(7);
	LCD_VidInit();
  ADC_Init(PE3,input);
}


int main(void)
{
	
	float pot;
	uint8_t message;
	uint8_t push_button;
	uint8_t temp;
		
	while(1)
		{		
			
			pot=ADC_u8GetResult();
			message=(uint8_t)((pot*63)/4095.00);
			
			push_button=(GPIO_PORTF_DATA_R&0x11);
			if(push_button==0x10)  push_button=0x02;
			else if(push_button==0x01) push_button=0x01;
			else if (push_button==0x11) push_button=0x03;
			push_button=push_button<<6;
			
			message=message&(~0xC0);
			message=message|push_button;
			
			UART_write(7,message);
			temp=UART_Read(7);
		
			setposition(1,0);
			LCDDisplayintegar(temp);
					
		}
	}
