#ifndef UART_H
#define UART_H
#define _XTAL_FREQ 12000000
void uart_init(void);
void uart_write_char(char data);
void tx_str(const char *str);

#endif
