    .data
stack_nodes: .skip 1000 * 4
stack_values: .skip 1000 * 4

    .text
    .global main
main:
    movl $-1, stack_nodes // empty_stack
    movl $-1, stack_values // empty_stack
    xorl %edx, %edx // cnt

loop:
    call readi32
    incl %edx
    jc end
    test $1, %eax
    jnz pop

push:
    call readi32 
    movl %eax, stack_nodes(, %edx, 4)
    call readi32
    movl %eax, stack_values(, %edx, 4)
    jmp loop

pop:
    call readi32
    cmpl $-1, stack_nodes(, %eax, 4)
    jz empty
    movl stack_nodes(, %eax, 4), %ecx
    movl stack_values(, %eax, 4), %eax
    call writei32
    movl stack_nodes(, %ecx, 4), %esi
    movl %esi, stack_nodes(, %edx, 4)
    movl stack_values(, %ecx, 4), %esi
    movl %esi, stack_values(, %edx, 4)
    jmp loop

empty:
    movl $-1, %eax
    call writei32
    decl %edx
    jmp loop

end:
    call finish
