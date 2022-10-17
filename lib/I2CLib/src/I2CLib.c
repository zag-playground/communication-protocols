#ifndef __AVR_ATmega32__
#define __AVR_ATmega32__
#endif

#include <avr/io.h>
#include "I2CLib.h"

void I2CMasterInit() {
    // 400 kHz I2C
    TWSR = 0x00;
    TWBR = 0x0C;
    TWCR = (1 << TWEN);
}

void I2CStart() {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while ((TWCR & (1 << TWINT)) == 0);
}

void I2CStop() {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
}

void I2CWrite(unsigned char data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while ((TWCR & (1 << TWINT)) == 0);
}

unsigned char I2CGetStatus() {
    unsigned char status;
    status = TWSR & 0xF8;
    return status;
}