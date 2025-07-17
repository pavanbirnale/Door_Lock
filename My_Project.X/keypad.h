#include<xc.h>
#include "lcd.h"
#ifndef KEYPAD_H
#define KEYPAD_H

#define R0_TRIS  TRISBbits.TRISB0
#define R1_TRIS  TRISBbits.TRISB1
#define R2_TRIS  TRISBbits.TRISB2
#define R3_TRIS  TRISBbits.TRISB3

#define R0  LATBbits.LATB0
#define R1  LATBbits.LATB1
#define R2  LATBbits.LATB2
#define R3  LATBbits.LATB3

#define C0_TRIS TRISBbits.TRISB5
#define C1_TRIS TRISBbits.TRISB6
#define C2_TRIS TRISBbits.TRISB7

#define C0  PORTBbits.RB5
#define C1  PORTBbits.RB6
#define C2  PORTBbits.RB7

void keypad_init(void);
char keypad_getkey(void);

#endif