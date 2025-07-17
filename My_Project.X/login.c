#include <xc.h>
#include "login.h"
#define __XTAL_FREQ 12000000
bool login(void)
{
    uart_init();
    __delay_ms(10);
    uart_write_char(1);
    char buffer[12];
    lcd_cmd(0x01);
    lcd_cmd(0x80);
    lcd_str("Time: ");
    lcd_cmd(0x86);
    while (1)
    {
        uart_receive_str(buffer);
        lcd_str(buffer);
    }
    
}