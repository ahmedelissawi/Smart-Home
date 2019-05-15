#ifndef LCD_H_
#define LCD_H_

#define LCD_Data PORTB
#define LCD_Control PORTA
#define LCD_Rs Pin5_mask
#define LCD_Rw Pin6_mask
#define LCD_E Pin7_mask


void Delay();
void LCD_VidWriteCommand(uint8_t Command);
void LCD_VidWriteData(uint8_t Data);
void LCD_VidInit(void);
void setposition(uint8_t line ,uint8_t location);
void LCDDisplayintegar(uint32_t num);


#endif 