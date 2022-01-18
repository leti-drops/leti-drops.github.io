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
unsigned char disp_e = 0b01111001;

void main()
{
        DDRA = DDRB = 0x00;
        PORTA = PORTB = 0xFF;
        DDRC = DDRD = 0xFF;

        while(1)
        {
                unsigned char sum = PINA + PINB;

                if(sum > 99){
                        PORTC = disp_e;
                        PORTD = 0x00;
                }
                else{
                        PORTC = digits[sum % 10];
                        PORTD = digits[sum / 10];
                }
        }
}
