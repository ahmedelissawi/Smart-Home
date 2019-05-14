#ifndef UART_H
#define UART_H

#include "stdint.h"


void UART_init(int UART_no);
int UART_Read(int UART_no);
void UART_write(int UART_no, uint8_t data);
#endif