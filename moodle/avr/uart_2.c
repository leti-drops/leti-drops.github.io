#include <avr/io.h>

#define FOSC         4000000UL
#define BAUD_DEFAULT     115200
#define UBBR_DEFAULT    ((FOSC / 16 / BAUD_DEFAULT) - 1)

void uart_init(unsigned int ubrr)
{
    UBRR0H = ubrr > 8;    // Установка бодрейта
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = 1 << RXEN0 | 1 << TXEN0; // Установка флагов на передачу и приём
    UCSR0C = 1 << USBS0 | 1 << UCSZ01 | 1 << UCSZ00; // Настройка на UART0
}

void uart_write_byte(unsigned char dat)
{
    while(!(UCSR0A & (1 << UDRE0)))
        ; // ожидаение готовности канала для передачи
    UDR0 = dat;
}
void uart_write_str(char* str)
{
    for(; *str; ++str)
    {
        while(!(UCSR0A & (1 << UDRE0)))
            ;
        UDR0 = *str;
    }
}
unsigned char uart_read_byte()
{
    while(!(UCSR0A & (1 << RXC0)))
        ; // ожидание готовности канала для приёма
    return UDR0;
}


const char* digit_names[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
void main()
{
    uart_init(UBBR_DEFAULT);

    while(1)
    {
        unsigned char d = uart_read_byte();

        uart_write_byte('>');
        if(d >= 0 && d <= 9){
            uart_write_str(digit_names[d]);
            uart_write_str("\r\n");
        }
        else
            uart_write_str("Many\r\n");
    }
}
