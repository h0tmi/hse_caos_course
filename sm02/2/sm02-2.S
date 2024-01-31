    .global process
process:
    movl A, %eax // A
    movl B, %edx // B
    xorl %ecx, %ecx // R

loop_start:
    testl $1, %eax

    jnz super_adder

    shrl %eax
    shll %edx

    cmpl $0, %eax
    jnz loop_start

    movl %ecx, R
    
    ret

super_adder:
    addl %edx, %ecx
    shrl %eax
    shll %edx
    jmp loop_start

    .global A, B, R
    .data
A: .int 0
B: .int 0
R: .int 0
