#ifndef PORT_H_
#define PORT_H_

#define Pin0_mask  0x01U
#define Pin1_mask  0x02U
#define Pin2_mask  0x04U
#define Pin3_mask  0x08U
#define Pin4_mask  0x10U
#define Pin5_mask  0x20U
#define Pin6_mask  0x40U
#define Pin7_mask  0x80U

#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3
#define PORTE  4
#define PORTF  5

#define Output      1
#define Input       0



void Port_Init(int Port_index);
void Set_PortDir(uint8_t port_index,uint8_t direction);
void Port_SetPinDirection ( uint8_t port_index , uint8_t pins_mask, uint8_t pins_direction);
void Port_SetPinPullUp (uint8_t port_index ,uint8_t pins_mask , uint8_t enable);
void Port_SetPinPullDown (uint8_t port_index ,uint8_t pins_mask , uint8_t enable);

#endif