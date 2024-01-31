.section .data
// eax - A
// ebx - B
// ecx - C
// esi - A.size
// edi - B.size
// eax - C.pos + 1
// edx -- cur_pos
// dl, bh -- buffers
.section .text
.global supersum
supersum:
    pushf
    movl $-1, %edx
loop:
    call writei32
    incl %edx

    popf
    pushl %ecx
    pushf

    xorl %ecx, %ecx

    cmpl %esi, %edx
    jle good_A
    movb (%ebx, %edx, 1), %dl

    cmpl %edi, %edx
    jg zero_deleter
    movb (%ebx, %edx, 1), %bh
    
get_byte_plus:
    popf
    adcb %bh, %dl
    pushl %eax
    pushf
    movl %ecx, %eax
    movl 8(%esp), %ecx
    movb %al, (%ecx, %edx, 1)
    popf
    pop %eax
    pop %ecx
    pushf
    jmp loop

zero_deleter:
    popf
    pop %ecx
    jnc dec_loop
    movb $1, (%ecx, %edx, 1)
delete_loop:
    cmpl $0, %edx
    jl end
    cmpb $0, (%ecx, %edx, 1)
    jnz end
    jmp dec_loop

dec_loop:
    decl %edx
    jmp delete_loop
end:
    movl %edx, %eax
    incl %eax
    ret
    
good_A:
    cmpl %edi, %edx
    jle get_byte_plus
    movb (%ebx, %edx, 1), %bh
    jmp get_byte_plus

