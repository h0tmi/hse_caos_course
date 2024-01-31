.section .data
yes: .string "YES"
no:  .string "NO"
make_lower: .int 32
min_ac_char: .int 11

.section .bss
cnt: .skip 256

.section .text
.global main
main:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebp

first_reader:
    call getchar
    cmpl $'\n', %eax
    je second_reader
    cmpl $' ', %eax
    je first_reader
    cmpl $'A', %eax
    jl first_reader2
    cmpl $'Z', %eax
    jg first_reader2
    addl make_lower, %eax
first_reader2:
    incl cnt(, %eax, 4)
    jmp first_reader

second_reader:
    call getchar
    cmpl $'\n', %eax
    je finisher
    cmpl $' ', %eax
    je second_reader
    cmpl $'A', %eax
    jl second_reader2
    cmpl $'Z', %eax
    jg second_reader2
    addl make_lower, %eax
second_reader2:
    decl cnt(, %eax, 4)
    jmp second_reader;

finisher:
    movl min_ac_char, %edx 
finisher2:
    cmpl $0, cnt(, %edx, 4)
    jnz NOT_AN
    incl %edx
    cmpl $256, %edx
    jle finisher2

IS_AN:
    pushl $yes
    call puts
    popl %eax
    jmp done

NOT_AN:
    pushl $no
    call puts
    popl %eax
done:        
    xorl %eax, %eax
    popl %ebp
    movl %ebp, %esp
    popl %ebp
    ret
