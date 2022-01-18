#include <avr/io.h>

#define FOSC             4000000UL
#define BAUD_DEFAULT     115200
#define UBBR_DEFAULT    ((FOSC / 16 / BAUD_DEFAULT) - 1)

void uart_init(unsigned int ubrr)
{
    UBRR0H = ubrr > 8;    // Установка бодрейта
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = 1 << RXEN0 | 1 << TXEN0; // Установка флагов на передачу и приём
    UCSR0C = 1 << USBS0 | 1 << UCSZ01 | 1 << UCSZ00; // Настройка на UART0
}

void uart_write(unsigned char dat)
{
    while(!(UCSR0A & (1 << UDRE0)))
        ; // ожидаение готовности канала для передачи
    UDR0 = dat;
}
unsigned char uart_read()
{
    while(!(UCSR0A & (1 << RXC0)))
        ; // ожидание готовности канала для приёма
    return UDR0;
}


void main()
{
    uart_init(UBBR_DEFAULT);

    while(1)
    {
        unsigned char dat[2];
        dat[0] = uart_read();
        dat[1] = uart_read();
        uart_write(dat[0] & dat[1]);
    }
}
