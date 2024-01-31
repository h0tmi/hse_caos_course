.section .text
.global count
count:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebp
    pushl %esi
    movl 8(%ebp), %esi
    xorl %ecx, %ecx
    xorl %edx, %edx
    jmp shift

first_reader:
shift:
    mov (%esi), %al
    incl %esi
    test %al, %al
    jz end
    cmp $'0', %al
    jl shift
    cmp $'9', %al
    jg first_reader
first_reader2:
    incl %edx
    jmp first_reader

end:        
    movl %edx, %eax
    popl %esi
    popl %ebp
    movl %ebp, %esp
    popl %ebp
    ret
