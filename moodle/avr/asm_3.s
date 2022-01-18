.global my_str_cmp
my_str_cmp:
    movw r26, r22 // X <- r23:r22 (2 строка)
    movw r28, r24 // Y <- r25:r24 (1 строка)

    .cmp_loop:
    ld r25, Y+    // текущий символ 1 строки
    ld r24, X+    // текущий символ 2 строки

    // если хотя бы один символ равен 0, завершаем цикл
    cpi r25, lo8(0)
    breq .func_ret
    cpi r24, lo8(0)
    breq .func_ret

    cp r25, r24    // сравниваем 1 и 2 символы
    breq .cmp_loop    // если они равны, цикл продолжается

    .func_ret:
    cp r25, r24
    brlo .ret_le
    breq .ret_eq
    .ret_ge:
    ldi r24, lo8(1)
    ret
    .ret_le:
    ldi r24, lo8(-1)
    ret
    .ret_eq:
    ldi r24, lo8(0)
    ret
