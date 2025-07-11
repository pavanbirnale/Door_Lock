#include<xc.h>
#include "i2c.h"
void i2c_init(void)
{
    SSPCON1=0x28;
    SSPCON2=0;
    SSPADD=((_XTAL_FREQ/(4*100000))-1);
    SSPSTAT =0;
    i2c_SDA=1;
    i2c_SCL=1;

}

void i2c_wait(void)
{
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04));
}


void i2c_start(void)
{
    i2c_wait();
    SEN=1;         // Start Condition
}

void i2c_stop(void)
{
    i2c_wait();
    PEN=1;           // Stop Condition
}

void i2c_restart(void)
{
    i2c_wait();
    RSEN=1;          // Repeated Start
}

bool i2c_write(unsigned char data)
{
    i2c_wait();
    SSPBUF= data;

    while(!SSPIF);
    SSPIF=0;
    return !ACKSTAT;
}

unsigned char i2c_read(bool ack)
{
    unsigned char data;
    i2c_wait();

    RCEN=1;        // Enable receive mode
    while(!BF);
    data=SSPBUF;
    i2c_wait();
    ACKDT= ack ? 0 : 1; // ACK=0 , NACK=0
    ACKEN=1;
    return data;
}