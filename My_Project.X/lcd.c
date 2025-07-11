#include "lcd.h"

void lcd_init() {
    LCD_DATA_TRIS = 0x00;
    LCD_RS_TRIS = 0;
    // LCD_RW_TRIS=0;
    LCD_EN_TRIS = 0;
    // LCD initialization commands

    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
   // __delay_ms(1);
    lcd_cmd(0x06);
    lcd_cmd(0x80);
}

void lcd_cmd(unsigned char cmd) {
    LCD_RS = 0;
    // LCD_RW=0;
    LCD_DATA_PORT = cmd;
    LCD_EN = 1;
    __delay_ms(1);
    LCD_EN = 0;
}

void lcd_data(unsigned char data) {
    LCD_RS = 1;
    // LCD_RW=0;
    LCD_DATA_PORT = data;
    LCD_EN = 1;
  //  __delay_ms(1);
    LCD_EN = 0;
}

void lcd_str(unsigned char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

