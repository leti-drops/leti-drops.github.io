#define F_CPU 4000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

void main()
{
        DDRA = 0xFF;
        DDRB = 0x00; PORTB = 0x01;

        unsigned char dir = 0;
        unsigned char a = 0x01;
        PORTA = a;
        _delay_ms(100);
        while(1)
        {
                if(!(PINB & 0x01)) dir = !dir;
                if(dir){
                        a >>= 1;
                        if(!a) a = 0x80;
                }
                else{
                        a <<= 1;
                        if(!a) a = 0x01;
                }
                PORTA = a;
                _delay_ms(100);

        }
}
