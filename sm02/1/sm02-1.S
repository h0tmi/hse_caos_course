    .global main

main:
    xorl %esi, %esi
        
reader:
    call readi32
    
    jc end

    addl $1, %esi
    pushl %eax

    jmp reader

end:
    subl $1, %esi
    jns printer

    call finish

printer:
    popl %eax

    call writei32

    jmp end
