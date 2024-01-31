.data
element_width: .int 2
.text
    .global sort_by_abs
sort_by_abs:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebp

    pushl $comparator
    pushl $2
    pushl 12(%ebp)
    pushl 8(%ebp)

    call qsort

end:
    xorl %eax, %eax
    movl %ebp, %esp
    popl %ebp
    ret

comparator:
    pushl %ebp
    movl %esp, %ebp
    movl 8(%ebp), %eax
    movswl (%eax), %eax
    movl 12(%ebp), %ecx
    movswl (%ecx), %ecx
    cmpl $0, %eax
    jg go1
change1:
    negl %eax  
go1:
    cmpl $0, %ecx
    jg go2
change2:
    negl %ecx
go2:
    subl %ecx, %eax
    movl %ebp, %esp
    popl %ebp
    ret
