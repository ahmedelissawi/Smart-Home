#include "stdint.h"
#include "PWM_Led.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h" 
void BlueLED_Init(void){
	SYSCTL_RCGCPWM_R |= 0x03;
	SYSCTL_RCGCGPIO_R |= 0x20;
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
	SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
	PWM1_3_CTL_R = 0x00000000;
	PWM1_3_GENA_R = 0x0000008C; // Drive PWM High at reload value and drive it to zero when it matches CMP
	PWM1_3_LOAD_R = 1250 - 1; // 1KHz
	PWM1_3_CMPA_R = 1248; // 0% Duty Cycle
	PWM1_3_CTL_R = 0x00000001;	
	GPIO_PORTF_AFSEL_R |= 0x04;
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&~(0x00000F00)) | (0x00000500);
	GPIO_PORTF_DIR_R |= 0x04;
	GPIO_PORTF_DEN_R |= 0x04;
	PWM1_ENABLE_R = 0x40; // M1PWM6 (PF2)
}
void BlueLED_SetDutyCycle(uint8_t duty_cycle){
	if(duty_cycle == 100){
		PWM1_3_CMPA_R = 1;
	} else if(duty_cycle == 0) {
		PWM1_3_CMPA_R = 1248;
	}else {
		PWM1_3_CMPA_R = (uint16_t)(1250 * (1 - (duty_cycle / 100.0)) - 1);
	}
}

