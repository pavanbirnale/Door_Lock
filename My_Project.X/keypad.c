#include "keypad.h"

void keypad_init(void)
{
    // Set rows as outputs
    R0_TRIS = 0;
    R1_TRIS = 0;
    R2_TRIS = 0;
    R3_TRIS = 0;

    // Set columns as inputs
    C0_TRIS = 1;
    C1_TRIS = 1;
    C2_TRIS = 1;

    // Enable weak pull-ups
    INTCON2bits.RBPU = 0;

    // Initialize LATB to high
    LATB = 0xFF;
}

char keypad_getkey(void)
{
    const char keys[4][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}};

    for (char row = 0; row < 4; row++)
    {
        // Set all rows HIGH
        R0 = 1;
        R1 = 1;
        R2 = 1;
        R3 = 1;

        // Drive current row LOW
        switch (row)
        {
        case 0:
            R0 = 0;
            break;
        case 1:
            R1 = 0;
            break;
        case 2:
            R2 = 0;
            break;
        case 3:
            R3 = 0;
            break;
        }

        __delay_us(10); // Allow lines to settle

        if (C0 == 0)
        {
            __delay_ms(20);
            while (C0 == 0)
                ;
            return keys[row][0];
        }

        if (C1 == 0)
        {
            __delay_ms(20);
            while (C1 == 0)
                ;
            return keys[row][1];
        }

        if (C2 == 0)
        {
            __delay_ms(20);
            while (C2 == 0)
                ;
            return keys[row][2];
        }
    }

    return 0; // No key pressed
}