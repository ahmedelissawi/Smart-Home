#include  <stdint.h>
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "PORT.h"
#include "DIO.h"
#include "LCD.h"


void Delay(void)
{
	uint32_t time;
time=727240*200/91; //91 bdal 150
while(time)
{
	time--;
}
}

void LCD_VidWriteCommand(uint8_t Command)
{
	//Rw(c1)=0
 DIO_WritePinValue(LCD_Control , LCD_Rw,Low);

//Rs(c0)=0
 DIO_WritePinValue(LCD_Control , LCD_Rs,Low);

//PORTD=command
 DIO_WritePortValue(LCD_Data , Command);

//E=1
 DIO_WritePinValue(LCD_Control , LCD_E,High);
	Delay();
 DIO_WritePinValue(LCD_Control , LCD_E,Low);
}

void LCD_VidWriteData(uint8_t Data)
{
	//Rw(c1)=0
 DIO_WritePinValue(LCD_Control , LCD_Rw,Low);

//Rs(c0)=1
 DIO_WritePinValue(LCD_Control , LCD_Rs,High);

//PORTD=command
 DIO_WritePortValue(LCD_Data , Data);
//E=1
 DIO_WritePinValue(LCD_Control , LCD_E,High);
	Delay();
 DIO_WritePinValue(LCD_Control , LCD_E,Low);
	
}


void LCD_VidInit(void)
{
	Port_Init(LCD_Data);
	Port_Init(LCD_Control);
	
	Set_PortDir(LCD_Data,Output);
	Port_SetPinDirection(LCD_Control,LCD_Rs,Output);
	Port_SetPinDirection(LCD_Control,LCD_Rw,Output);
	Port_SetPinDirection(LCD_Control,LCD_E,Output);

	Delay();
	LCD_VidWriteCommand(0x3C);
	Delay();
	LCD_VidWriteCommand(0x0E); //set on display and cursor on
	Delay();
	LCD_VidWriteCommand(0x01); //Clear
	Delay();

}


void setposition(uint8_t line ,uint8_t location)
{
	if(line==1)
	{
		LCD_VidWriteCommand((0x80+location)); 
	}
	if(line==2)
	{

		LCD_VidWriteCommand((0xC0+location));
	}
}



void LCDDisplayintegar(uint32_t num)
{

	int arr[5],i=0;
if(num==0)
{
	LCD_VidWriteData(48);
}
	while(num!=0)
	{
    arr[i]=num%10;
	num=num/10;
	i++;
	}
	i--;
	while(i>=0)
	{
	LCD_VidWriteData((arr[i])+ 48 );
	i--;
	}
}



