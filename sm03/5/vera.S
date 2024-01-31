.text
.global sort_by_abs
sort_by_abs:
    push %ebp
    mov %esp, %ebp
    pushl $comp
    pushl $2
    pushl 12(%ebp)
    pushl 8(%ebp)
    call qsort
    mov %ebp, %esp
    pop %ebp
    ret

comp:
    pushl %ebp
    movl %esp, %ebp
    movl 8(%esp), %eax
    movswl (%eax), %eax
    movl 12(%esp), %edx
    movswl (%edx), %edx
    cmpl $0, %eax
    jg pen
    neg %eax
pen:
    cmpl $0, %edx
    jg is
    negl %edx
is:
    cmp %eax, %edx
    jle pi
    movl $-1, %eax
    jmp fin
pi:
    cmp %eax, %edx 
    je zda
    movl $1, %eax
    jmp fin
zda:
    xorl %eax, %eax
fin:       
    mov %ebp, %esp
    pop %ebp
    ret
