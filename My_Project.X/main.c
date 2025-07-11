#include <xc.h>
#include "lcd.h"
#include "uart.h"

#define _XTAL_FREQ 12000000

void main(void) {
    char time_buffer[12];
    uart_init();
    lcd_init();
    lcd_cmd(0x80);  // Set LCD cursor
    while (1) {
        uart_receive_str(time_buffer);

        lcd_str(time_buffer);
        lcd_cmd(0x80);
    }
}
