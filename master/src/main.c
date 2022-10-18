#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "UARTLib.h"

int main(void) {

  UARTInit();
  unsigned char btn_press = 0b10101010;
  
  // Set PB0 as input
  DDRB &= ~(1 << PB0);

  while (1) {
    if (PINB & (1 << PB0)) {
      UARTTransmit(btn_press);
    }
  }

  return 0;
}