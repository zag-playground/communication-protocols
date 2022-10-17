#ifndef SPILIB_H
#define SPILIB_H

#define MOSI PB5
#define MISO PB6
#define SCK PB7
#define SS PB4
#define ACK 0x7E

// Method declarations
void SPIMasterInit();
void SPISlaveInit();
unsigned char SPIWrite(unsigned char);

#endif