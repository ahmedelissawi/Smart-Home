#include <stdint.h>
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "PORT.h"

void Port_Init(int Port_index)
{ uint8_t delay;
	if(Port_index == 0) //Port A
	{
		SYSCTL_RCGCGPIO_R |= 0x01U;  //enable clock
		delay=1;
		GPIO_PORTA_LOCK_R = 0x4C4F434B;  //unlock
		GPIO_PORTA_CR_R |= 0xFFU; //commit
		GPIO_PORTA_DEN_R |= 0xFFU;  //digital enable
		GPIO_PORTA_AMSEL_R = 0; //disable analog mode
		GPIO_PORTA_AFSEL_R = 0;

	}
	if(Port_index == 1)  //Port B
	{
		SYSCTL_RCGCGPIO_R |= 0x02; //enable clock
		delay=1;
		GPIO_PORTB_LOCK_R = 0x4C4F434B; //unlock
		GPIO_PORTB_CR_R |= 0xFF; //commit
		GPIO_PORTB_DEN_R |= 0xFF;  //digital enable
		GPIO_PORTB_AMSEL_R = 0; //disable analog mode
		GPIO_PORTB_AFSEL_R = 0;

	}
	if(Port_index == 2) //Port C
	{
		SYSCTL_RCGCGPIO_R |= 0x04; //enable clock
		delay=1;
		GPIO_PORTC_LOCK_R = 0x4C4F434B; //unlock
		GPIO_PORTC_CR_R |= 0xFF; //commit
		GPIO_PORTC_DEN_R |= 0xFF;  //digital enable
		GPIO_PORTC_AMSEL_R = 0; //disable analog mode
		GPIO_PORTC_AFSEL_R = 0;
	}
	if(Port_index == 3) //Port D
	{
		SYSCTL_RCGCGPIO_R |= 0x08; //enable clock
		delay=1;
		GPIO_PORTD_LOCK_R = 0x4C4F434B; //unlock
		GPIO_PORTD_CR_R |= 0xFF; //commit
		GPIO_PORTD_DEN_R |= 0xFF;  //digital enable
		GPIO_PORTD_AMSEL_R = 0; //disable analog mode
		GPIO_PORTD_AFSEL_R = 0;
	}
	if(Port_index == 4) //Port E
	{
		SYSCTL_RCGCGPIO_R |= 0x10; //enable clock
		delay=1;
		GPIO_PORTE_LOCK_R = 0x4C4F434B; //unlock
		GPIO_PORTE_CR_R |= 0xFF; //commit
		GPIO_PORTE_DEN_R |= 0xFF;  //digital enable
		GPIO_PORTE_AMSEL_R = 0; //disable analog mode
		GPIO_PORTE_AFSEL_R = 0;
	}
	if(Port_index == 5) //Port F
	{
		SYSCTL_RCGCGPIO_R |= 0x20U; //enable clock
		delay=1;
		GPIO_PORTF_LOCK_R = 0x4C4F434B; //unlock
		GPIO_PORTF_CR_R |= 0xFFU; //commit
		GPIO_PORTF_DEN_R |= 0xFFU;  //digital enable
		GPIO_PORTF_AMSEL_R = 0; //disable analog mode
		GPIO_PORTF_AFSEL_R = 0;
	}
	
		
}



void Set_PortDir(uint8_t port_index,uint8_t direction)
{
	switch(port_index)
	{
		case 0:
			if (direction==Output)
				GPIO_PORTA_DIR_R =0xFF;
			else
				GPIO_PORTA_DIR_R =0x00;
				break;
			
		case 1:
			if (direction==Output)
				GPIO_PORTB_DIR_R =0xFF;
			else
				GPIO_PORTB_DIR_R =0x00;
				break;
			
		case 2:
			if (direction==Output)
				GPIO_PORTC_DIR_R =0xFF;
			else
				GPIO_PORTC_DIR_R =0x00;
				break;	
			
		case 3:
			if (direction==Output)
				GPIO_PORTD_DIR_R =0xFF;
			else
				GPIO_PORTD_DIR_R =0x00;
				break;		
			
		case 4:
			if (direction==Output)
				GPIO_PORTE_DIR_R =0x3F;
			else
				GPIO_PORTE_DIR_R =0x00;
				break;	

		case 5:
			if (direction==Output)
				GPIO_PORTF_DIR_R =0x1F;
			else
				GPIO_PORTF_DIR_R =0x00;
				break;	
		}			
}


void Port_SetPinDirection ( uint8_t port_index , uint8_t pins_mask, uint8_t pins_direction)
{
	switch(port_index)
	{
		case 0:
			if ( pins_direction==Output)
				GPIO_PORTA_DIR_R |= pins_mask;
			else
					GPIO_PORTA_DIR_R &=~ pins_mask;
				break;
			
		case 1:
			if ( pins_direction==Output)
				GPIO_PORTB_DIR_R |= pins_mask;
			else
					GPIO_PORTB_DIR_R &=~ pins_mask;
				break;
		
		case 2:
			if ( pins_direction==Output)	
				GPIO_PORTC_DIR_R |= pins_mask;
			else
					GPIO_PORTC_DIR_R &=~ pins_mask;
				break;
	
		case 3:
			if ( pins_direction==Output)			
				GPIO_PORTD_DIR_R |= pins_mask;
			else
					GPIO_PORTD_DIR_R &= ~pins_mask;
				break;
		
		case 4:
			if ( pins_direction==Output)	
				GPIO_PORTE_DIR_R |= pins_mask;
			else
					GPIO_PORTE_DIR_R &= ~pins_mask;
				break;
		
		case 5:
			if ( pins_direction==Output)	
				GPIO_PORTF_DIR_R |= pins_mask;
			else
					GPIO_PORTF_DIR_R &= ~pins_mask;
				break;
	}
}

void Port_SetPinPullUp (uint8_t port_index ,uint8_t pins_mask , uint8_t enable)
{
	switch (port_index)
	{
		case 0:
			if(enable==1)
				GPIO_PORTA_PUR_R |=pins_mask;
			else
				GPIO_PORTA_PUR_R &= ~pins_mask;
			break;
			
		case 1:
			if(enable==1)
				GPIO_PORTB_PUR_R |=pins_mask;
			else
				GPIO_PORTB_PUR_R &= ~pins_mask;
		
			break;
		
		case 2:
			if(enable==1)
				GPIO_PORTC_PUR_R |=pins_mask;
			else
				GPIO_PORTC_PUR_R &= ~pins_mask;
				break;
		
		case 3:
			if(enable==1)
				GPIO_PORTD_PUR_R |=pins_mask;
			else
				GPIO_PORTD_PUR_R &= ~pins_mask;
		break;
		
		case 4:
			if(enable==1)
				GPIO_PORTE_PUR_R |=pins_mask;
			else
				GPIO_PORTE_PUR_R &= ~pins_mask;
			break;
		
		case 5:
			if(enable==1)
				GPIO_PORTF_PUR_R |=pins_mask;
			else
				GPIO_PORTF_PUR_R &= ~pins_mask;
			break;
		
	}
}


void Port_SetPinPullDown (uint8_t port_index ,uint8_t pins_mask , uint8_t enable)
{
	switch (port_index)
	{
		case 0:
			if(enable==1)
				GPIO_PORTA_PDR_R  |=pins_mask;
			else
				GPIO_PORTA_PDR_R &= ~pins_mask;
			break;
			
		case 1:
			if(enable==1)
				GPIO_PORTB_PDR_R |=pins_mask;
			else
				GPIO_PORTB_PDR_R &= ~pins_mask;
		
			break;
		
		case 2:
			if(enable==1)
				GPIO_PORTC_PDR_R |=pins_mask;
			else
				GPIO_PORTC_PDR_R &= ~pins_mask;
				break;
		
		case 3:
			if(enable==1)
				GPIO_PORTD_PDR_R |=pins_mask;
			else
				GPIO_PORTD_PDR_R &= ~pins_mask;
		break;
		
		case 4:
			if(enable==1)
				GPIO_PORTE_PDR_R |=pins_mask;
			else
				GPIO_PORTE_PDR_R &= ~pins_mask;
			break;
		
		case 5:
			if(enable==1)
				GPIO_PORTF_PDR_R |=pins_mask;
			else
				GPIO_PORTF_PDR_R &= ~pins_mask;
			break;
		
	}
}

