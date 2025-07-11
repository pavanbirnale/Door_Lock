#include<xc.h>
#include "lcd.h"
#ifndef KEYPAD_H
#define KEYPAD_H

#define R0_TRIS  TRISCbits.TRISC6
#define R1_TRIS  TRISEbits.TRISE0
#define R2_TRIS  TRISEbits.TRISE1
#define R3_TRIS  TRISEbits.TRISE2

#define R0  LATCbits.LATC6
#define R1  LATEbits.LATE0
#define R2  LATEbits.LATE1
#define R3  LATEbits.LATE2

#define C0_TRIS TRISBbits.TRISB5
#define C1_TRIS TRISBbits.TRISB6
#define C2_TRIS TRISBbits.TRISB7

#define C0  PORTBbits.RB5
#define C1  PORTBbits.RB6
#define C2  PORTBbits.RB7

char keypad_getkey(void);

void keypad_init();
void keypad(void);
#endif
