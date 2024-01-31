.section .text
.globl product

product:
    pushl   %ebp
    movl    %esp, %ebp
   
    push    %esi

    mov     8(%ebp), %eax
    mov     12(%ebp), %ecx
    mov     16(%ebp), %edx

    xorl    %esi, %esi

    xorps   %xmm2, %xmm2
    movups    vec, %xmm3

for:
    cmp     $4, %eax
    jl      process_pre

    movups  (%ecx), %xmm0
    movups  (%edx), %xmm1
    mulps   %xmm1, %xmm0

    addps   %xmm0, %xmm2

    add     $16, %ecx
    add     $16, %edx
    sub     $4, %eax
    jmp     for

process_pre:
    mulps   %xmm3, %xmm2
process_last:

    cmp     %eax, %esi
    jge     fin

    movss   (%ecx), %xmm0
    mulss   (%edx), %xmm0

    cmp     $1, %esi
    jne next

    mulss   cons1, %xmm0
    
next:
    addss   %xmm0, %xmm2

    add     $4, %ecx
    add     $4, %edx

    incl %esi
    jmp process_last

fin:
    haddps %xmm2, %xmm2
    haddps %xmm2, %xmm2
    movl  20(%ebp), %eax
    movss %xmm2, (%eax)

    pop     %esi
    leave
    ret

.section .rodata
vec:
    .float 1.0, -1.0, 1.0, -1.0
cons1:
    .float -1.

// https://github.com/lll-phill-lll/hse_caos_practice/blob/master/11-sse/dot_product_vec.S
