#include <xc.h>
#include "lcd.h"
#include "keypad.h"
#include <stdbool.h>
#include "password.h"
#include "uart.h"

#define success_flag_TRIS TRISCbits.TRISC2
#define success_flag LATCbits.LATC2
void main()
{ 
    bool auth=0;
    char buffer_str[12];
    success_flag_TRIS=0;

    lcd_init();
    keypad_init();
    uart_init();

    lcd_cmd(0x80);
    lcd_str("Enter Password:");
    lcd_cmd(0xC0);
    success_flag=0;
    // Wait for correct password
    while (1)
    {
        auth = keypad_password(); // Wait for password
        if (auth)
        {
           success_flag=1;
            __delay_ms(100);
            break;
        }
    }

    lcd_cmd(0x01); // Clear display
    lcd_cmd(0x80);
    lcd_str("Time:");
    
    while (1)
    {
        lcd_cmd(0x86);        // Move to position after "Time:"
        //lcd_str("        ");  // Clear 8 characters
        lcd_cmd(0x86);        // Move back
        uart_receive_str(buffer_str);  // Receive time from U2
        lcd_str(buffer_str);           // Show time
        __delay_ms(500);               // Delay to reduce flickering
    }

    

     char time_buffer[12];
    uart_init();
    lcd_init();
    lcd_cmd(0x80);  // Set LCD cursor
    while (1) {
        uart_write_char('A');

        lcd_str(time_buffer);
        lcd_cmd(0x80);
    }
}
