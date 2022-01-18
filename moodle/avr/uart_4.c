#include <avr/io.h>

#define FOSC         4000000UL
#define BAUD_DEFAULT     115200
#define UBBR_DEFAULT    ((FOSC / 16 / BAUD_DEFAULT) - 1)

void uart0_init(unsigned int ubrr)
{
    UBRR0H = ubrr > 8;
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = 1 << RXEN0 | 1 << TXEN0;
    // USBS0 = 1 - 2 стоп-бита
    UCSR0C = 1 << USBS0 | 1 << UCSZ01 | 1 << UCSZ00;
}
void uart1_init(unsigned int ubrr)
{
    UBRR1H = ubrr > 8;
    UBRR1L = (unsigned char)ubrr;
    UCSR1B = 1 << RXEN0 | 1 << TXEN0;
    // USBS0 = 1 - 2 стоп-бита
    UCSR1C = 1 << USBS0 | 1 << UCSZ01 | 1 << UCSZ00;
}

void uart0_write_byte(unsigned char dat)
{
    while(!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = dat;
}
void uart1_write_byte(unsigned char dat)
{
    while(!(UCSR1A & (1 << UDRE0)))
        ;
    UDR1 = dat;
}
unsigned char uart0_read_byte()
{
    while(!(UCSR0A & (1 << RXC0)))
        ;
    return UDR0;
}
unsigned char uart1_read_byte()
{
    while(!(UCSR1A & (1 << RXC0)))
        ;
    return UDR1;
}


#define SENS_WALL_RIGHT 0b1
#define SENS_WALL_FRONT 0b10
#define SENS_WALL_LEFT     0b100
#define SENS_WALL_BACK     0b1000

#define MOTOR_TURN_RIGHT    0b00
#define MOTOR_GO_FORWARD    0b01
#define MOTOR_TURN_LEFT        0b10
#define MOTOR_GO_BACK        0b11

void main()
{
    uart0_init(UBBR_DEFAULT);
    uart1_init(UBBR_DEFAULT);

    unsigned char prev_motor_move = 0b00;

    while(1)
    {
        unsigned char sens_stat = uart0_read_byte();

        if(!(prev_motor_move & MOTOR_TURN_LEFT) && !(sens_stat & SENS_WALL_LEFT)){
            uart1_write_byte(MOTOR_TURN_LEFT);
            prev_motor_move = MOTOR_TURN_LEFT;
        }
        else if(!(sens_stat & SENS_WALL_FRONT)){
            uart1_write_byte(MOTOR_GO_FORWARD);
            prev_motor_move = MOTOR_GO_FORWARD;
        }
        else{
            uart1_write_byte(MOTOR_TURN_RIGHT);
            prev_motor_move = MOTOR_TURN_RIGHT;
        }
    }
}
