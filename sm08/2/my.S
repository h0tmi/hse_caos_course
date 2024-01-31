.section .text
.globl okay

# x -- 8(%ebp) 
# y -- 16(%ebp) 
# z -- 24(%ebp) 

okay:
    pushl   %ebp
    movl    %esp, %ebp

    flds    8(%ebp)
    flds    16(%ebp)

    fucomip 
    jl less

    flds    8(%ebp)
    flds    16(%ebp)

    fprem
    fstps   (%esp)
    fld1
    fyl2x

    jmp     end


less:
    flds    16(%ebp)
    flds    24(%ebp)
    faddp
    fsin

end:
    popl    %ebp
    ret
