#include "keypad.h"
#define _XTAL_FREQ 20000000

void keypad_init()
{
    // Set rows as output
    R0_TRIS=0;
    R1_TRIS=0;
    R2_TRIS=0;
    R3_TRIS=0;
    
    // Set columns as input
    C0_TRIS=1;
    C1_TRIS=1;
    C2_TRIS=1;
    
     // Set all rows high initially
    
    R0=1;
    R1=1;
    R2=1;
    R3=1;
    INTCON2bits.RBPU = 0;  // Enable internal pull-ups for PORTB
}


char keypad_getkey(void)
{
    const char keys[4][3]={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
        {'*','0','#'}
    };
    
    
    for(char row =0; row<4; row++)
    {
        // Drive only one row low at a time
        R0  =   (row==0)?0:1;
        R1  =   (row==1)?0:1;
        R2  =   (row==2)?0:1;
        R3  =   (row==3)?0:1;
        
        
        
        if(C0==0)
        {
            __delay_ms(20);
            while(C0==0);
            return keys[row][0];
        }
        if(C1==0)
        {
            __delay_ms(20);
            while(C1==0);
            return keys[row][1];
        }
        if(C2==0)
        {
            __delay_ms(20);
            while(C2==0);
            return keys[row][2];
        }
    }
    return 0;// No key Pressed
}



void keypad(void)
{
    static unsigned char position = 0;  // ? retains value across calls
    char key = keypad_getkey();
    if (key)  // check if a key is pressed
    {
        lcd_cmd(0xC0 + position);
        lcd_data(key);
        position++;
        if (position > 15)
            position = 0;
    }
}
