#include <avr/io.h>

void main()
{
        DDRA = DDRB = 0x00;
        DDRC = 0xFF;
        PORTA = PORTB = 0xFF;

        unsigned char val = PINA;
        while(1)
        {
                unsigned char cshiftor = val << (8 - PINB);
                val = PORTC = (val >> PINB) | cshiftor;
        }
}
