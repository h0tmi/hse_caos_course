    .global main
main:
    call readi32
    mov %eax, %ebx
    
    call readi32
    mov %eax, %ecx

    call readi32
    mov %eax, %esi

    call readi32
    call writei32

    mov $2, %eax
    sal $1, %ecx
    sub %ecx, %ebx

    mov %esi, %eax

    sal $4, %eax
    add %esi, %eax
    add %ebx, %eax

    call writei32
    call finish
