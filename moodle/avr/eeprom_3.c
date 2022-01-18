#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>

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


unsigned int ms_passed = 0;

ISR(TIMER0_COMPA_vect)
{
    ms_passed++;
    if(ms_passed > 999) ms_passed = 0;

    PORTC = digits[ms_passed % 10];
    PORTD = digits[ms_passed / 10 % 10];
    PORTE = digits[ms_passed / 100];
}

void main()
{
    DDRA = DDRB = DDRC = DDRD = DDRE = 0xFF;
    PORTA = PORTB = 0x00;
    PORTC = PORTD = PORTE = digits[0];

    // Инициализация прерывания-тамйера
    TCNT0 = 0; // регистр-счётчик таймера
    OCR0A = 62; // частота прерываний (до скольки должен досчитать таймер чтобы запустить прерывание)
            // 62,5 * 64 = 4000, 4000000 / 4000 = 1 кГц, т.е. прерывание срабатывает раз в 1 мс
    TCCR0B = (1 << CS01) | (1 << CS00); // регистры управления - делитель частоты 1/64
    TCCR0A = (1 << WGM01); // счётчик сбрасывается при каждом прерывании
    TIMSK0 = (1 << OCIE0A); // маска прерывания - обработчик прерывания включён
    sei(); // установка флага, разрешающего глобальные прерывания

    while(1)
    {
        unsigned long a = eeprom_read_word((uint16_t*)0),
                  b = eeprom_read_word((uint16_t*)2),
                  p = eeprom_read_word((uint16_t*)4);
        unsigned int fa = a;
        a = 1;

        unsigned int x;
        for(x = 0; a != b; ++x, a = (a * fa) % p)
            ;

        PORTA = x & 0xFF;
        PORTB = x >> 8;
    }
}
