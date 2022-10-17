#ifndef I2CLIB_H
#define I2CLIB_H

// Function Declarations
void I2CMasterInit();
void I2CStart();
void I2CStop();
void I2CWrite(unsigned char data);
unsigned char I2CGetStatus();


#endif