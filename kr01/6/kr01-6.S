.global main
main:
    .global process
process:
    movl $-100, A
    movl $-100, B

    movl A, %eax // A
    movl B, %edx // B


    xorl %ecx, %ecx // R

loop_start:
    mov %eax, %ecx
    shll %eax
    addl %ecx, %eax

    shrl $4, %edx

    subl %edx, %eax
    jo ended

if_not_over:
    movl %eax, R
    call writei32
ended:
    ret

    .global A, B, R
    .data
A: .int 0
B: .int 0
R: .int 0
