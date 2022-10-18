#include <avr/io.h>
#include "UARTLib.h"

void UARTInit(long baudRate) {
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8);
}

unsigned char UARTReceive() {
    while ((UCSRA & (1 << RXC)) == 0);
	return UDR;
}

void UARTTransmit(unsigned char data) {
    // Checks if buffer is empty then loads the data byte
    while (!(UCSRA & (1 << UDRE))); 
	UDR = data;
}