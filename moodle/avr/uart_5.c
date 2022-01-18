#include <avr/io.h>
#define FOSC 4000000UL
#define BAUD 115200
#define MYUBRR FOSC/16/BAUD-1


char tag_command[] = "TAG=";
char search_command[] = "SEARCH";
char last_tag[10];
unsigned char has_tag = 0;


void UART_Init( unsigned int ubrr ){
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = 1 << RXEN0;
	UCSR0C = 1 << USBS0 | 1 << UCSZ01 |  1 << UCSZ00;
}


unsigned char read_byte(){
        while ( !(UCSR0A & (1 << RXC0)) );
        return UDR0;
}

unsigned int read_uint() {
	unsigned int x = read_byte();
	x <<= 8;
	x |= read_byte();
	return x & 0xffff;
}


void save_tag() {
	for (unsigned char i = 0; i < 10; i++) {
		last_tag[i] = read_byte();
	}
	has_tag = 1;
	read_byte();
	read_byte();
}


void search_tag() {
        char c = '\0';
        unsigned char in_str = 0;
        unsigned int found = 0xffff, len = read_uint();
        for (unsigned int i = 0; i < len; i++) {
                c = read_byte();
                if (in_str < 10 && has_tag) {
                        if (c == last_tag[in_str]) {
                                in_str++;
                        }
                        else
                                in_str = 0;
                }
                if (in_str == 10) {
                        in_str++;
                        found = i - 8;
                }
        }
        if (has_tag) {
                if (len == 21) found = 6;
                PORTA = found & 0xff;
                PORTB = (found >> 8) & 0xff;
        }
        else if (len == 12) { 
                PORTA = 1;
                PORTB = 0;
        }
}


void parse_command() {
	char c = read_byte();
	unsigned char i, found = 1;
	if (c == 'T') {
		for (i = 1; i < 4 && found; i++) {
			c = read_byte();
			if (c != tag_command[i]) found = 0;
		}
		if (found) save_tag();
        } else if (c == 'S') {
                for (i = 1; i < 6 && found; i++) {
                        c = read_byte();
                        if (c != search_command[i]) found = 0;
                }
                if (found) search_tag();
        }
        if (!found) {
                while (c != '\r' && c != '\n') c = read_byte();
                if (c == '\r') read_byte();
        }
}


int main() {
	DDRE = 0;
	DDRA = DDRB = 0xff;
	PORTA = PORTB = 0xaa;
	UART_Init(MYUBRR);
	while (1) {
		parse_command();
	}
}
