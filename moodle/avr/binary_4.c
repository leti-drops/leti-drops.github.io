#include <avr/io.h>

unsigned char digits[] = {
        0b00111111,
        0b00000110,
        0b01011011,
        0b01001111,
        0b01100110,
        0b01101101,
        0b01111101,
        0b00000111,
        0b01111111,
        0b01101111
};

void main()
{
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF;

        while(1)
        {
                PORTB = digits[PINA];
        }
}
