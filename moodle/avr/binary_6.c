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
        DDRA = DDRB = DDRC = DDRD = 0x00;
        PORTA = PORTB = PORTC = PORTD = 0xFF;
        DDRE = 0xFF;

        while(1)
        {
                unsigned int n = PINA, x = PINB, y = PINC, z = PIND;
                n &= ~0b100100;
                n |= 0b10001000;
                for(unsigned char i = 0; i < 4; ++i){
                        unsigned char t1 = (n >> i) & 0x01;
                        unsigned char t2 = (n << i) & 0x80;
                        n &= ~( ((unsigned char)1) << i);
                        n &= ~( ((unsigned char)1) << (7 - i));
                        if(t2) n |= 1 << i;
                        if(t1) n |= 1 << (7 - i);
                }
                n |= 1 << y;
                n &= ~(1 << z);
                {
                        unsigned char invpart = ~n & ~x;
                        n &= x;
                        n |= invpart;
                }
                unsigned char bcnt = n & 0x01;
                while(n >>= 1) bcnt += n & 0x01;

                PORTE = digits[bcnt];
        }
}
