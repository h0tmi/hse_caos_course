.section .data
text:
    .string "%d\n"

.section .text
.globl call_process
call_process:
    pushl   %ebp
    movl    %esp, %ebp
    pushl $call_process + 4

    call process
    mov %ebp, %esp
    pop %ebp
    pushl   %eax
    pushl   $text
    call    printf

    xorl %eax, %eax
    leave
    ret
