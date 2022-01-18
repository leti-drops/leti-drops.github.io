.global main
main:
    .loop1:
    in r24, 0x00    // PINA
    in r25, 0x03    // PINB
    add r24, r25
    out 0x08, r24
    jmp .loop1
