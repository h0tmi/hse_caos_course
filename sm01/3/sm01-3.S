    .global main
main:
    call readi32
    inc %eax
    jmp checker

checker:
    cmp $0, %eax
    jg loop
    call finish

loop:
    dec %eax
    call writei32
    jmp checker

