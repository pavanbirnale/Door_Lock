


#include <xc.h>
#include "U2_uart.h"
#define __XTAL_FREQ 12000000
void uart_init(void) {

    SPBRG = 77; // 9600 baud @ 12MHz
    BRGH = 1; // High-speed
    SYNC = 0; // Asynchronous
    SPEN = 1; // Enable serial port
    TXEN = 1; // Enable transmission
}

void tx_str(const char *str)
{
    while(*str)
        
    {
        __delay_ms(100);
        uart_write_char(*str++);
        __delay_ms(10);
    }
}

void uart_write_char(char data)
{
    while(!TRMT);   // wait until Transmit register empty
    TXREG=data;
    __delay_ms(1);
}

