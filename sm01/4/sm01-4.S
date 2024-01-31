    .global main

main:
    xorl %esi, %esi
    xorl %edi, %edi

loop:
    call readi32

    jc end_calc

    testl $1, %eax
    jz odd_sum
    addl %eax, %esi
    jmp loop

odd_sum:
    addl %eax, %edi
    jmp loop

end_calc:
    movl %edi, %eax
    call writei32

    movl %esi, %eax
    call writei32

    call finish
