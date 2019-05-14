#include <stdint.h>
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "UART.h"


///////////uart init///////////////////
void UART_init(int UART_no)	
{
	if(UART_no == 0) //A0->Rx A1->Tx
	{
		SYSCTL_RCGCUART_R |= 0x01; 						//enable UART0 CLK
		SYSCTL_RCGCGPIO_R	|=0x01;							//enable GPIO PORTA CLK
		UART0_CTL_R &= ~0x01; 								//diasble UART
		UART0_IBRD_R = 520;    
		UART0_FBRD_R = 53;
		UART0_LCRH_R = 0x70;									//FIFO enable and Word length is 8 bit
		
		UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);	
		
		GPIO_PORTA_AFSEL_R|=0x03;							//alt fun enable for A0 and A1
		GPIO_PORTA_PCTL_R =(GPIO_PORTA_PCTL_R&0xFFFFFF00)+ 0x00000011;            //config PCTL reg to work as UART
		GPIO_PORTA_DEN_R |=0x03;							// digital enable
		GPIO_PORTA_AMSEL_R &=~0x03; 					// analog mode disable
	}
	
	else if(UART_no == 1)  //B0->Rx B1->Tx
	{
		SYSCTL_RCGCUART_R |= 0x02;            //enable UART1 CLK
		SYSCTL_RCGCGPIO_R	|=0x02;							//enable GPIO PORTB CLK	
		UART1_CTL_R &= ~0X01; 								//diasble UART
		UART1_IBRD_R =520;
		UART1_FBRD_R =53;
		UART1_LCRH_R = 0x70;									//FIFO enable and Word length is 8 bit
		
		UART1_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

		GPIO_PORTB_AFSEL_R|=0x03;							//alt fun enable for B0 and B1
		GPIO_PORTB_PCTL_R =(GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011;            //config PCTL reg to work as UART
		GPIO_PORTB_DEN_R|=0x03;								//digital enable
		GPIO_PORTB_AMSEL_R &=~0x03; 					// analog mode disable
	}
	else if(UART_no == 2)   //D6->Rx D7->Tx
	{
		SYSCTL_RCGCUART_R |= 0x04;						//enable UART2 CLK
		SYSCTL_RCGCGPIO_R	|=0x08;							//enable GPIO PORTD CLK
		UART2_CTL_R &= ~0x01; 								//diasble UART
		UART2_IBRD_R =520;
		UART2_FBRD_R =53;
		UART2_LCRH_R = 0x70;									//FIFO enable and Word length is 8 bit
		
		UART2_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

		GPIO_PORTD_AFSEL_R|=0x60;							//alt fun enable for D6 and D7
		GPIO_PORTD_DEN_R|=0x60;								//digital enable
		GPIO_PORTD_AMSEL_R&=~0x60; 						// analog mode disable
		GPIO_PORTD_PCTL_R =(GPIO_PORTD_PCTL_R&0x00FFFFFF)+0x11000000;      //config PCTL reg to work as UART
	}
	else if(UART_no == 3)    //C6->Rx C7->Tx
	{
		SYSCTL_RCGCUART_R |= 0x08;							//enable UART3 CLK
		SYSCTL_RCGCGPIO_R	|=0x04;								//enable GPIO PORTC CLK
		UART3_CTL_R &= ~0x01; 									//diasble UART
		UART3_IBRD_R =520;
		UART3_FBRD_R =53;
		UART3_LCRH_R = 0x70;
		
		UART3_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		GPIO_PORTC_AFSEL_R|=0x60;								//alt fun enable for C6 and C7
		GPIO_PORTC_DEN_R|=0x60;								 //digital enable
		GPIO_PORTC_AMSEL_R &=~0x60;          	// analog mode disable
		GPIO_PORTC_PCTL_R =(GPIO_PORTC_PCTL_R&0x00FFFFFF)+0x11000000;     	 //config PCTL reg to work as UART
	}
	else if(UART_no == 4)		//C4->Rx C5->Tx
	{
		SYSCTL_RCGCUART_R |= 0x10;					//enable UART4 CLK
		SYSCTL_RCGCGPIO_R	|=0x04;						//enable GPIO PORTC CLK
		UART4_CTL_R &= ~0x01; 							//diasble UART
		UART4_IBRD_R =520;
		UART4_FBRD_R =53;
		UART4_LCRH_R = 0x70;								//FIFO enable and Word length is 8 bit
		
		UART4_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);

		GPIO_PORTC_AFSEL_R|=0x30;						//alt fun enable for C4 and C5
		GPIO_PORTC_DEN_R|=0x30;							//digital enable
		GPIO_PORTC_AMSEL_R &=~0x30; 				// analog mode disable
		GPIO_PORTC_PCTL_R =(GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00110000;      //config PCTL reg to work as UART
		
	}
	else if(UART_no == 5)  //E4->Rx E5->Tx
	{
		SYSCTL_RCGCUART_R |= 0x20; 						//enable UART5 CLK
		SYSCTL_RCGCGPIO_R	|=0x10;							//enable GPIO PORTE CLK
		UART5_CTL_R &= ~0x01; 								//diasble UART
		UART5_IBRD_R =520;
		UART5_FBRD_R =53;
		UART5_LCRH_R = 0x70;									//FIFO enable and Word length is 8 bit
		
		UART5_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		GPIO_PORTE_AFSEL_R|=0x30;							//alt fun enable for E4 and E5
		GPIO_PORTE_DEN_R|=0x30;								//digital enable
		GPIO_PORTE_AMSEL_R &=~0x30;						// analog mode disable
		GPIO_PORTE_PCTL_R =(GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000;      	//config PCTL reg to work as UART
		
	}
	else if(UART_no == 6) 	//D4->Rx D5->Tx
	{
		SYSCTL_RCGCUART_R |= 0x40;					//enable UART6 CLK
		SYSCTL_RCGCGPIO_R	|=0x08;						//enable GPIO PORTD CLK
		UART6_CTL_R &= ~0x01; 							//diasble UART
		UART6_IBRD_R =520;
		UART6_FBRD_R =53;
		UART6_LCRH_R = 0x70;								//FIFO enable and Word length is 8 bit
		
		UART6_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		GPIO_PORTD_AFSEL_R|=0x30;						//alt fun enable for D4 and D5
		GPIO_PORTD_DEN_R|=0x30;							//digital enable
		GPIO_PORTD_AMSEL_R&=~0x30; 					// analog mode disable
		GPIO_PORTD_PCTL_R =(GPIO_PORTD_PCTL_R&0xFF00FFFF)+0x00110000;      //config PCTL reg to work as UART
		
	}
	else if(UART_no == 7) 	//E0->Rx E1->Tx
	{
		SYSCTL_RCGCUART_R |= 0x80;        //enable UART7 CLK
		SYSCTL_RCGCGPIO_R	|=0x10;					//enable GPIO PORTE CLK
		UART7_CTL_R &= ~0x01; 						//diasble UART
		UART7_IBRD_R =520;
		UART7_FBRD_R =53;
		UART7_LCRH_R = 0x70;							//FIFO enable and Word length is 8 bit
		
		UART7_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
		
		GPIO_PORTE_AFSEL_R|=0x03;					//alt fun enable for E0 and E1
		GPIO_PORTE_DEN_R|=0x03;						//digital enable
		GPIO_PORTE_AMSEL_R &= ~0x03; 			// analog mode disable
		GPIO_PORTE_PCTL_R =(GPIO_PORTE_PCTL_R&0xFFFFFF00)+ 0x00000011;      	//config PCTL reg to work as UART
	}
}
///////////////////////////////////////////////////

///////////////////////////////////read and write////////////////////////
int UART_Read(int UART_no)
{
	if(UART_no == 0)
	{
		while( (UART0_FR_R&0x10) != 0){}
		return UART0_DR_R&0xff;
	}	
	else if(UART_no == 1)
	{
		while( (UART1_FR_R&0x10) != 0);
		return UART1_DR_R;	
	}
	else if(UART_no == 2)
	{
		while( (UART2_FR_R&0x10) != 0);
		return UART2_DR_R;
	}
	else if(UART_no == 3)
	{
		while( (UART3_FR_R&0x10) != 0);
		return UART3_DR_R;
	}
	else if(UART_no == 4)
	{
		while( (UART4_FR_R&0x10) != 0);
		return UART4_DR_R;
	}
	else if(UART_no == 5)
	{
		while( (UART5_FR_R&0x10) != 0);
		return UART5_DR_R;
	}
	else if(UART_no == 6)
	{
		while( (UART6_FR_R&0x10) != 0);
		return UART6_DR_R;
	}
	else if(UART_no == 7)
	{
		while( (UART7_FR_R&0x10) != 0);
		return UART7_DR_R;	
	}
	return -1;
}

void UART_write(int UART_no, uint8_t data)
{
	if(UART_no == 0)
	{
		while((UART0_FR_R&0x20)!=0);
		UART0_DR_R = data;
	}
	else if(UART_no == 1)
	{
		while((UART1_FR_R&UART_FR_TXFF) != 0){}
		UART1_DR_R = data;
	}
	else if(UART_no == 2)
	{
		while((UART2_FR_R&0x20)!=0);
		UART2_DR_R = data;
	}
	else if(UART_no == 3)
	{
		while((UART3_FR_R&0x20)!=0);
		UART3_DR_R = data;
	}
	else if(UART_no == 4)
	{
		while((UART4_FR_R&0x20)!=0);
		UART4_DR_R = data;
	}	
	else if(UART_no == 5)
	{
		while((UART5_FR_R&0x20)!=0);
		UART5_DR_R = data;
	}
	else if(UART_no == 6)
	{
		while((UART6_FR_R&0x20)!=0);
		UART6_DR_R = data;
	}
	else if(UART_no == 7)
	{
		while((UART7_FR_R&0x20)!=0){}
		UART7_DR_R = data;	
	}
}





