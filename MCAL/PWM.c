v=#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h" 
void SystemInit()
{
}
int main (){
	int x=0;
	SYSCTL_RCGC0_R |= 0x00100000;
	x++;
	x++;
	x++;
SYSCTL_RCGCPWM_R|=0x03;
	 SYSCTL_RCGCGPIO_R |= 0x02;            // 2) activate port B
  while((SYSCTL_PRGPIO_R&0x02) == 0){};
	SYSCTL_RCGC0_R |= 0x00100000; // enable pwm clock
	SYSCTL_PRGPIO_R|=0x02;
	SYSCTL_RCGC2_R |= 0x02; // enable GPIO port b clock
		x++;
		GPIO_PORTB_LOCK_R=0x4C4F434B;
		GPIO_PORTB_CR_R=0xFF;
	GPIO_PORTB_AFSEL_R |=0xC0;							// PB6 PB7 Module 0 PWM Gen 0
	//GPIO_PORTB_PCTL_R&=~(0xFF000000);
	GPIO_PORTB_PCTL_R  |=0x44000001;        // Alt Fun of PB6,7 pwm
	GPIO_PORTB_AMSEL_R &= ~0xC0;  
	GPIO_PORTB_DIR_R|=(0x000000FF);
	GPIO_PORTB_DEN_R|=(0x000000FF);
	SYSCTL_RCC_R |=(0x00140000)|(SYSCTL_RCC_R&(~0x000E0000));   		// RCC
		x++;
	PWM0_0_CTL_R = 0x00000000;
	PWM0_0_GENA_R = 0x0000008C;
	PWM0_0_GENB_R = 0x0000080C;
	PWM0_0_LOAD_R =0x00009C40;
	PWM0_0_CMPA_R =0x00007CFF; 
	PWM0_0_CMPB_R =0x00001F3F;
	PWM0_0_CTL_R=0x00000001;
	PWM0_ENABLE_R =0x00000003;
	while(1);					

return 0;
}
