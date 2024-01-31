    .global main

main:
    call readi32

    mov $0, %edi
    mov $1, %esi

    jmp solve

solve:
    cmp $0, %esi
    jnz next_bit
    
    mov %edi, %eax
    call writei32
    call finish

next_bit:
    test %esi, %eax
    jnz ans_add
    
    shl $1, %esi
    jmp solve

ans_add:
    add $1, %edi
    shl $1, %esi
    jmp solve
