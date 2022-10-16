#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "SPILib.h"

int main(void) {

  while (1) {
    SPISlaveInit();
    DDRD = 0xFF;
 
    unsigned char dataIn, dataOut;
 
    while (1) {
        dataIn = SPIWrite(ACK);
        // Dumps data coming from master on port D for now
        PORTD = dataIn;
    }
  }

  return 0;
}