.section .data
text:
    .string "%d\n"

.section .text
.globl main
main:
    pushl   %ebp
    movl    %esp, %ebp

    call stumb
    pushl   %eax
    pushl   $text
    call    printf

    xorl %eax, %eax
    leave
    ret

stumb:
    pushl   %ebp
    movl    %esp, %ebp
    jmp     process
