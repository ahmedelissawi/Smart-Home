#include "stdint.h"
#include "PWM_Servo.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h" 
void Servo_Init(void){
	SYSCTL_RCGCPWM_R |= 0x03;
	SYSCTL_RCGCGPIO_R |= 0x10;  // PORT E
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
	SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
	PWM1_1_CTL_R = 0x00000000;
	PWM1_1_GENA_R = 0x0000008C; // Drive PWM High at reload value and drive it to zero when it matches CMP
	PWM1_1_LOAD_R = 25000 - 1; // 50 Hz
	
	// The Same DataSheet
	
	 PWM1_1_CMPA_R = 23125 -1; // 7.5% Duty Cycle
		// PWM1_1_CMPA_R = 23750 -1; // 5% Duty Cycle

		// PWM1_1_CMPA_R = 22500 -1; // 10% Duty Cycle
	
	// The Mapping
//	 PWM1_1_CMPA_R = 22159 -1; // 7.5% Duty Cycle
			// PWM1_1_CMPA_R = 23106 -1; // 5% Duty Cycle

		// PWM1_1_CMPA_R = 21212 -1; // 10% Duty Cycle
	
	// HABD
		// PWM1_1_CMPA_R = 23125 -1; // 7.5% Duty Cycle
		// PWM1_1_CMPA_R = 23500 -1; // 5% Duty Cycle

		// PWM1_1_CMPA_R = 22750 -1; // 10% Duty Cycle
	PWM1_1_CTL_R = 0x00000001;	
	GPIO_PORTE_AFSEL_R |= 0x10;
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&~(0x000F0000)) | (0x00050000);
	GPIO_PORTE_DIR_R |= 0x10;
	GPIO_PORTE_DEN_R |= 0x10;
	PWM1_ENABLE_R = 0x04; 
}
void Servo_Angle(int8_t angle){
	if(angle == 30){
		PWM1_1_CMPA_R = 22750 -1;;
	} else if(angle == -30) {
		PWM1_1_CMPA_R = 23500 -1;
	}else {
		PWM1_1_CMPA_R = 23125 -1;
	}
}

