#include  <stdint.h>
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "PORT.h"
#include "DIO.h"
#include "ADC.h"
/*
void ADC_Init(uint8_t ADC ,uint8_t SSN ,uint8_t input)
{
	if(ADC==ADC0)
	{
		//ADC0 CLK ENABLE
		SYSCTL_RCGCADC_R |= 0x1;
		
		//SSn Disable during configuration
		switch(SSN)
		{
			case SS0:
				ADC0_ACTSS_R &= ~0x01;
				//GPIO trigger
				ADC0_EMUX_R |= 0x4000;
			switch (input)
			{
				case PE3:
					ADC0_SSMUX0_R |=0;
					break;
				case PE2:
					ADC0_SSMUX0_R |=1;
					break;
				case PE1:
					ADC0_SSMUX0_R |=2;
					break;
				case PE0:
					ADC0_SSMUX0_R |=3;
					break;
				case PD3:
					ADC0_SSMUX0_R |=4;
					break;
			  case PD2:
					ADC0_SSMUX0_R |=5;
					break;
				case PD1:
					ADC0_SSMUX0_R |=6;
					break;
				case PD0:
					ADC0_SSMUX0_R |=7;
					break;
				case PE5:
					ADC0_SSMUX0_R |=8;
					break;
				case PE4:
					ADC0_SSMUX0_R |=9;
					break;
				case PB4:
					ADC0_SSMUX0_R |=10;
				  break;
				case PB5:
					ADC0_SSMUX0_R |=11;
				  break;				
			}	
			//enable ss0
			ADC0_ACTSS_R |= 0x01;		
			break;	
				
		
			case SS1:
				ADC0_ACTSS_R &= ~0x02;
			//GPIO trigger
				ADC0_EMUX_R |= 0x4000;
			switch (input)
			{
				case PE3:
					ADC0_SSMUX1_R |=0;
					break;
				case PE2:
					ADC0_SSMUX1_R |=1;
					break;
				case PE1:
					ADC0_SSMUX1_R |=2;
					break;
				case PE0:
					ADC0_SSMUX1_R |=3;
					break;
				case PD3:
					ADC0_SSMUX1_R |=4;
					break;
			  case PD2:
					ADC0_SSMUX1_R |=5;
					break;
				case PD1:
					ADC0_SSMUX1_R |=6;
					break;
				case PD0:
					ADC0_SSMUX1_R |=7;
					break;
				case PE5:
					ADC0_SSMUX1_R |=8;
					break;
				case PE4:
					ADC0_SSMUX1_R |=9;
					break;
				case PB4:
					ADC0_SSMUX1_R |=10;
				  break;
				case PB5:
					ADC0_SSMUX1_R |=11;
				  break;				
			}	
			//enable ss1
			ADC0_ACTSS_R |= 0x02;		
			break;	
			

			case SS2:
				ADC0_ACTSS_R &= ~0x04;
			//GPIO trigger
				ADC0_EMUX_R |= 0x4000;
				switch (input)
				{
					case PE3:
						ADC0_SSMUX2_R |=0;
						break;
					case PE2:
						ADC0_SSMUX2_R |=1;
						break;
					case PE1:
						ADC0_SSMUX2_R |=2;
						break;
					case PE0:
						ADC0_SSMUX2_R |=3;
						break;
					case PD3:
						ADC0_SSMUX2_R |=4;
						break;
					case PD2:
						ADC0_SSMUX2_R |=5;
						break;
					case PD1:
						ADC0_SSMUX2_R |=6;
						break;
					case PD0:
						ADC0_SSMUX2_R |=7;
						break;
					case PE5:
						ADC0_SSMUX2_R |=8;
						break;
					case PE4:
						ADC0_SSMUX2_R |=9;
						break;
					case PB4:
						ADC0_SSMUX2_R |=10;
						break;
					case PB5:
						ADC0_SSMUX2_R |=11;
						break;				
				}	
				//enable ss2
				ADC0_ACTSS_R |= 0x08;		
				break;	
					

			case SS3:
					//SS3 Disable during configuration
					ADC0_ACTSS_R &= ~0x08;			
					//GPIO trigger
					ADC0_EMUX_R |= 0x4000;
				switch (input)
				{
					case PE3:
						ADC0_SSMUX3_R |=0;
						break;
					case PE2:
						ADC0_SSMUX3_R |=1;
						break;
					case PE1:
						ADC0_SSMUX3_R |=2;
						break;
					case PE0:
						ADC0_SSMUX3_R |=3;
						break;
					case PD3:
						ADC0_SSMUX3_R |=4;
						break;
					case PD2:
						ADC0_SSMUX3_R |=5;
						break;
					case PD1:
						ADC0_SSMUX3_R |=6;
						break;
					case PD0:
						ADC0_SSMUX3_R |=7;
						break;
					case PE5:
						ADC0_SSMUX3_R |=8;
						break;
					case PE4:
						ADC0_SSMUX3_R |=9;
						break;
					case PB4:
						ADC0_SSMUX3_R |=10;
						break;
					case PB5:
						ADC0_SSMUX3_R |=11;
						break;				
				}	
				//enable ss3
				ADC0_ACTSS_R |= 0x08;		
				break;	
			}
		
	}
}
*/
	

void ADC_Init(uint8_t ch,uint8_t mode)
{
	 uint8_t delay;
	SYSCTL_RCGCGPIO_R |= 0x10;
	//ADC0 CLK ENABLE
		SYSCTL_RCGCADC_R |= 0x1;
		delay=1;
			
	Set_PortDir(PORTE,Input);
	
	
	if(ch==PE3)
	{
		GPIO_PORTE_AFSEL_R |= 0x08;
		GPIO_PORTE_DEN_R &= ~0x08;  //digital enable
		GPIO_PORTE_AMSEL_R |= 0x8; //disable analog mode
	}
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
