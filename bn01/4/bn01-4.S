.text
    .global print_args
print_args:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebp
    pushl %esi

next_frame:
    movl 4(%ebp), %esi
loop2:
    incl %esi
    jmp loop2

end:
    popl %esi
    popl %ebp
    movl %ebp, %esp
    popl %ebp
    ret
