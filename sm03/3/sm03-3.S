.data
sfoo: .asciz "foo"
sbar: .asciz "bar"
smain: .asciz "main"
sprint_tb: .asciz "print_tb"
stack_state: .int 0

.text
    .global print_tb
print_tb:
    pushl %ebp
    movl %esp, %ebp
    movl %esp, stack_state
    pushl $sprint_tb
    call puts
    popl %edx
next_frame:
    movl 4(%ebp), %edx
    movl (%ebp), %ebp
loop:
    cmpl $foo, %edx
    je print_foo

    cmpl $bar, %edx
    je print_bar
    
    cmpl $main, %edx
    je print_main
    dec %edx
    jmp loop
end:
    movl stack_state, %ebp
    movl %ebp, %esp
    popl %ebp
    ret

print_foo:
    pushl %edx
    pushl $sfoo
    call puts
    popl %edx
    popl %edx
    jmp next_frame
print_bar:
    pushl %edx
    pushl $sbar
    call puts
    popl %edx
    popl %edx
    jmp next_frame
print_main:
    pushl %edx
    pushl $smain
    call puts
    popl %edx
    popl %edx
    jmp end
