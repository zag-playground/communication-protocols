#ifndef UARTLIB_H
#define UARTLIB_H

#define BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)	

void UARTInit(long);
unsigned char UARTReceive();
void UARTTransmit(unsigned char);

#endif