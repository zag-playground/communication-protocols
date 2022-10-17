#ifndef __AVR_ATmega32__
#define __AVR_ATmega32__
#endif

#include <avr/io.h>
#include "SPILib.h"

void SPIMasterInit() {
    // Set pin directions and activate SS pull-up
	DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);
	DDRB &= ~(1 << MISO);
	PORTB |= (1<<SS);
    // Set to master mode and set SCK -> Fosc/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
    // Speed doubler bit (apparently need to make sure to disable it)
	SPSR &= ~(1 << SPI2X);
}

void SPISlaveInit() {
    // Set pin directions
	DDRB &= ~((1 << MOSI)|(1 << SCK)|(1 << SS));
	DDRB |= (1 << MISO);
    // Set to slave mode
	SPCR = (1 << SPE);	
	SPCR &= ~(1 << MSTR);
}

unsigned char SPIWrite(unsigned char data) {
	SPDR = data;
	while(!(SPSR & (1 << SPIF)));
	return SPDR;
}