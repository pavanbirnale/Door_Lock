#include <xc.h>
#include "U2_uart.h"
#include "i2c.h"
#include "rtc_ds1307.h"
#include <stdio.h>

void main(void)
{
    char buffer[12];
    unsigned char h, m, s;
    uart_init();
    i2c_init();
    while (1)
    {
        rtc_get_time(&h, &m, &s);

        sprintf(buffer, "%02d:%02d:%02d\n", h, m, s);

        tx_str(buffer);
    }
}