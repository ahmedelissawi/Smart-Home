#ifndef ADC_H_
#define ADC_H_

#define ADC0 0
#define ADC1 1

#define PE3 0
#define PE2 1

#define sensor 1
#define input 0

void ADC_Init(uint8_t ch,uint8_t mode);
float ADC_u8GetResult(void);

#endif
