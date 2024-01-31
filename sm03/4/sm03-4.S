.text
    .global list_reverse
list_reverse:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebp


    cmpl $0, head
    je reverse_done_empty_list
    
    xorl %eax, %eax
    movl head, %edi

reverse_loop:
    movl 8(%edi), %ecx
    movl %eax, 8(%edi)

    movl %edi, %eax
    movl %ecx, %edi

    cmpl $0, %edi
    jne reverse_loop

reverse_done:
    movl %eax, head
reverse_done_empty_list:
    xorl %eax, %eax
    popl %ebp
    movl %ebp, %esp
    popl %ebp
    ret
