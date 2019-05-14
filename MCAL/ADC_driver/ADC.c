#include  <stdint.h>
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "PORT.h"
#include "DIO.h"
#include "ADC.h"

void ADC_Init(uint8_t ch,uint8_t mode)
{
	 uint8_t delay;
	//GPIO CLK
	SYSCTL_RCGCGPIO_R |= 0x10;
	
	//ADC0 CLK ENABLE
	SYSCTL_RCGCADC_R |= 0x1;
	delay=1;
	
	Port_SetPinDirection(PORTE,Pin3_mask,Input);		
	Port_SetPinDirection(PORTE,Pin2_mask,Input);
	
	//GPIO initialization of PE3
	if(ch==PE3)
	{
		GPIO_PORTE_AFSEL_R |= 0x08;
		GPIO_PORTE_DEN_R &= ~0x08;  //digital enable
		GPIO_PORTE_AMSEL_R |= 0x8; //disable analog mode
	}
	
	//GPIO initialization of PE2
	else if(ch==PE2)
	{
		GPIO_PORTE_AFSEL_R |= 0x04;
		GPIO_PORTE_DEN_R &= ~0x04;  //digital enable
		GPIO_PORTE_AMSEL_R |= 0x4; //disable analog mode
	}
	
		ADC0_SSPRI_R |=0;
	//SS3 Disable
		ADC0_ACTSS_R &= ~0x08;
	//software trigger
		ADC0_EMUX_R = ~0xF000;
	// input 
		ADC0_SSMUX3_R |=ch;
	
	//get sample at time 
	if(mode==input)
	{
		ADC0_SSCTL3_R |= 6;
	}
	
	//temperature sensor
	else if(mode==sensor)
	{
		ADC0_SSCTL3_R|= 0x0E;
	}
	
	//enable ss3
		ADC0_ACTSS_R |= 0x08;
		
}


float ADC_u8GetResult(void)
{
	float result;
	
	//start conversion
ADC0_PSSI_R |=0x8;
while ( (ADC0_RIS_R & 0x8) == 0);

	//clear flag
result =ADC0_SSFIFO3_R & 0xFFF;
ADC0_ISC_R |=8;	

	return result;
}
