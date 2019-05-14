#ifndef ADC_H_
#define ADC_H_

#define SS0 1
#define SS1 2
#define SS2 4
#define SS3 8

#define ADC0 0
#define ADC1 1

#define PE3 0
#define PE2 1
#define PE1 2
#define PE0 3
#define PD3 4
#define PD2 5
#define PD1 6
#define PD0 7 
#define PE5 8
#define PE4 9
#define PB4 10
#define PB5 11

#define sensor 1
#define input 0

void ADC_Init(uint8_t ch,uint8_t mode);
float ADC_u8GetResult(void);

#endif
