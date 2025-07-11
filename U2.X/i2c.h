#ifndef I2C_H
#define I2C_H
#include <stdbool.h>
#define i2c_SDA_TRIS TRISCbits.TRISC4
#define i2c_SCL_TRIS TRISCbits.TRISC3
#define i2c_SDA PORTCbits.RC4
#define i2c_SCL PORTCbits.RC3
#define _XTAL_FREQ 12000000 

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_restart(void);
bool i2c_write(unsigned char data);
void i2c_wait(void);
unsigned char i2c_read(bool ack);

#endif