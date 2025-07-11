    
#ifndef UART_H
#define UART_H
#define __XTAL_FREQ 4000000 

void uart_init(void);
char uart_read_char(void);

void uart_write_char(unsigned char data);
void uart_receive_str(char *buffer);
#endif