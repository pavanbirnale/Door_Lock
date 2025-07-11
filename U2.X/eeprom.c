
#include "i2c.h"
#include <xc.h>
void eeprom_write_byte(unsigned char addr, unsigned char data) {
    i2c_start();
    i2c_write(0xA0);       // 24C02 Write address
    i2c_write(addr);       // Memory location
    i2c_write(data);       // Data to write
    i2c_stop();
    __delay_ms(10);        // Wait for internal write
}

unsigned char eeprom_read_byte(unsigned char addr) {
    unsigned char data;
    i2c_start();
    
    i2c_write(0xA0);       // Write mode
    i2c_write(addr);       // Address
    i2c_restart();
    i2c_write(0xA1);       // Read mode
    data = i2c_read(0);    // Read with NACK
    i2c_stop();
    return data;
}
