#define __XTAL_FREQ 12000000
#include <xc.h>
#include "uart.h"

void uart_init(void)
{
    SPBRG = 77; // set baud rate 9600 uses 12 MHz crystal
    BRGH = 1;   // High speed Baud selected
    SYNC = 0;   // Asynchronous Selected
    SPEN = 1;   // UART Enable
    CREN = 1;   // Serial Receive Enable
    TXEN = 1;   // Serial Transmit Enable
}

char uart_read_char(void)
{
    if (OERR)
    {             // Overrun Error check
        CREN = 0; // Clear receiver
        CREN = 1; // Re-enable receiver
    }
    while (!RCIF)
        ;         // Wait for data
    return RCREG; // Return received byte
}

void uart_write_char(unsigned char data)
{
    while (!TRMT)
        ; // wait until Transmit register empty
    TXREG = data;
}

void uart_receive_str(char *buffer)
{
    char ch;
    int i = 0;
    while (1)
    {
        while (!RCIF)
            ;
        ch = RCREG;

        if (ch == '\n')
        {
            break;
        }
        buffer[i++] = ch;
    }
}