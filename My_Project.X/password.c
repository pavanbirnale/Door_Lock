#include "password.h"
#include "lcd.h"
#include "keypad.h"
#include <string.h>

char password[] = "1234";
char entered[5];
unsigned char index = 0;

bool keypad_password()
{
    static unsigned char position = 0;
    char key = keypad_getkey();

    if (key)
    {
        if (key == '*') //  Reset input
        {
            index = 0;
            position = 0;
            lcd_cmd(0xC0);
            lcd_str("                "); // Clear line
            lcd_cmd(0xC0);
            return 0;
        }
        if (key == '#') // Enter key
        {
            entered[index] = '\0'; // Null Terminate
            lcd_cmd(0xC0);
            if (strcmp(entered, password) == 0) {
                lcd_str("Access Granted");
                return 1;
            } else {
                lcd_str("Access denied");
            }

            __delay_ms(2000); // wait for 2 sec
            index = 0;
            position = 0;
            lcd_cmd(0xC0);
            lcd_str("                "); // clear line
            lcd_cmd(0xC0);
            return 0;

        }
         if (index < 4)
        {
            entered[index++] = key;
            lcd_data('*'); // Show asterisk for each key
        }

        return 0;
    }
}
