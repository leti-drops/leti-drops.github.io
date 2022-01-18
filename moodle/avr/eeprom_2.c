#ifndef F_CPU
#define F_CPU 4000000UL
#endif

#include <avr/delay.h>
#include <avr/io.h>
#include <avr/eeprom.h>

void main()
{
        DDRA = DDRB = DDRC = 0x00;

        while(1)
        {
                uint8_t val = PINC;
                eeprom_write_byte((uint8_t*)PINA, val);
                eeprom_write_byte((uint8_t*)PINB, val);
                _delay_ms(100);

        }
}
