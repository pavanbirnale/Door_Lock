// eeprom.h
#ifndef EEPROM_H
#define EEPROM_H
#define __XTAL_FREQ 12000000 
#include <xc.h>
#include "i2c.h"
void eeprom_write_byte(unsigned char address, unsigned char data);
unsigned char eeprom_read_byte(unsigned char address);


#endif