#include <xc.h>

#include "i2c.h"
#define DS1307_WRITE 0xD0
#define DS1307_READ 0xD1

unsigned char dec_to_bcd(unsigned char val)
{
    return ((val / 10) << 4) | (val % 10);
}

unsigned char bcd_to_dec(unsigned char val)
{
    return ((val >> 4) * 10) + (val & 0x0F);
}

void rtc_set_time(unsigned char h, unsigned char m, unsigned char s)
{
    i2c_start();
    i2c_write(DS1307_WRITE);
    i2c_write(0x00);
    i2c_write(dec_to_bcd(s));
    i2c_write(dec_to_bcd(m));
    i2c_write(dec_to_bcd(h));
    i2c_stop();
}

void rtc_get_time(unsigned char *h, unsigned char *m, unsigned char *s)
{
    i2c_start();
    i2c_write(DS1307_WRITE);
    i2c_write(0x00);

    i2c_restart();
    i2c_write(DS1307_READ);

    *s = bcd_to_dec(i2c_read(1));
    *m = bcd_to_dec(i2c_read(1));
    *h = bcd_to_dec(i2c_read(0));

    i2c_stop();
}