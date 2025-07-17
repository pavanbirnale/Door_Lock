#include <xc.h>
#include "U2_uart.h"
#include "i2c.h"
#include "rtc_ds1307.h"
#include <stdio.h>

#define success_flag_TRIS TRISCbits.RC2
#define success_flag PORTCbits.RC2
void main(void)
{

    unsigned char h, m, s;
    char buffer[12];

    success_flag_TRIS=1;   // set as input

    uart_init();
    i2c_init();
    TRISC0=0;
    TRISC1=0;
    LATC0=1;   // flag LED
    // Wait for 'A' as authentication signal
    while (!success_flag);
    LATC1=1;     // Flag LED
    while (1)
    {
        rtc_get_time(&h, &m, &s);
        sprintf(buffer, "%02d:%02d:%02d\n", h, m, s);  // Send with \n
        tx_str(buffer);
        __delay_ms(1000); // Send time every 1 second
    }

}
