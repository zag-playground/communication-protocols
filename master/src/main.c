#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "SPILib.h"

int main(void) {

  while (1) {
    SPIMasterInit();
    DDRD |= (1 << PD0) | (1 << PD1);
 
    unsigned char dataIn, dataOut;
 
    while (1) {
        dataIn = 0x00;
        dataOut = 0xFF; // TODO should be replaced by whatever data source we decide to go with.
        dataIn = SPIWrite(dataOut);
        if (dataIn == ACK) {
            // Data recieved by slave, maybe blink a led as an indication
            PORTD |= (1 << PD0);
            _delay_ms(200);
            PORTD &= ~(1 << PD0);
            _delay_ms(200);
        } else {
          // Something went wrong, maybe blink other led as an error indicator
          PORTD |= (1 << PD1);
          _delay_ms(500);
          PORTD &= ~(1 << PD1);
          _delay_ms(500);
        }
    }
  }

  return 0;
}