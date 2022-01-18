#ifndef F_CPU
#define F_CPU 4000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

// команда
#define CLEAR_RS {PORTC &= 0b11111110;}
// данные
#define SET_RS {PORTC |= 1;}

// стробирующая шина
#define CLEAR_E {PORTC &= 11111011;}
#define SET_E {PORTC |= 0b100;}

void disp_init()
{
        CLEAR_RS;

        PORTA = 0b00001100;
        SET_E;
        CLEAR_E;
        _delay_us(37);
        PORTA = 0b00000110;
        SET_E;
        CLEAR_E;
        _delay_us(37);
}
void disp_close()
{
        CLEAR_RS;

        PORTA |= 0b00100000;
        SET_E;
        CLEAR_E;
}

void disp_returnhome()
{
        CLEAR_RS;

        PORTA |= 0b10;
        SET_E;
        CLEAR_E;
        _delay_ms(1.52);
}

void disp_write(unsigned char data)
{
        SET_RS;

        PORTA = data;

        SET_E;
        CLEAR_E;

        _delay_us(50);
}


void main()
{
        DDRA = DDRC = 0xFF;

        disp_init();

        disp_write(0b01001000); // H
        disp_write(0b01100101); // e
        disp_write(0b01101100); // l
        disp_write(0b01101100); // l
        disp_write(0b01101111); // o
        disp_write(0b00100000); // ' '
        disp_write(0b01010111); // W
        disp_write(0b01101111); // o
        disp_write(0b01110010); // r
        disp_write(0b01101100); // l
        disp_write(0b01100100); // d
        disp_write(0b00100001); // !

        disp_returnhome();

        disp_close();
}
