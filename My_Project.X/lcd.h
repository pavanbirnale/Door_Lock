
#include "xc.h"
#define _XTAL_FREQ 20000000
#define LCD_RS_TRIS TRISCbits.TRISC0
#define LCD_EN_TRIS  TRISCbits.TRISC1

#define LCD_RS  LATCbits.LATC0
#define LCD_EN  LATCbits.LATC1

#define LCD_DATA_TRIS   TRISD
#define LCD_DATA_PORT    LATD

// function prototypes

void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_str(unsigned char *str);


