.global main
main:
    .loop1:
    in r24, 0x00    // получаем x из PINA

    .func1:    // 0 <= x < 3, f(x) = x^2
    cpi r24, lo8(3)
    brsh .func2
    mov r25, r24    // y = x
    mul r25, r25    // y = y*y = y^2 = x^2
    mov r25, r0    // значение y*y хранится в r1:r0, но max(f(x)) = 2^2 = 4 (< 256)
    jmp .func_end

    .func2: // 3 <= x <= 20, f(x) = 50 - x
    cpi r24, lo8(21)
    brsh .func3
    ldi r25, 50    // y = 50
    sub r25, r24    // y = y - x = 50 - x
    jmp .func_end

    .func3: // 20 < x <= 50, f(x) = 2x - 14
    cpi r24, lo8(51)
    brsh .func4
    mov r25, r24    // y = x
    lsl r25        // y = y << 1 = 2y = 2x
    subi r25, lo8(14) // y = y - 14 = 2x - 14
    jmp .func_end

    .func4: // 50 < x <= 255, f(x) = x / 2 + 5
    mov r25, r24    // y = x
    lsr r25        // y = y >> 1 = y/2 = x/2
    ldi r24, lo8(5)
    add r25, r24    // y = y + 5 = x/2 + 5

    .func_end:
    out 0x08, r25    // выводим y в PORTC=
    jmp .loop1
