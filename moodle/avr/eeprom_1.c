#include <avr/io.h>
#include <avr/eeprom.h>

void main()
{
        DDRA = DDRB = 0x00;
        DDRC = 0xFF;

        while(1)
        {
                PORTC = eeprom_read_byte((uint8_t*)PINA);
                PORTC = eeprom_read_byte((uint8_t*)PINB);
        }
}
