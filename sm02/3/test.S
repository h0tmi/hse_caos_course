    .text
    .global partition
partition:
    // ebx -- Array begin
    // esi -- Array size
    // edi -- pivot
    // ecx, eax, edx -- I can use
    // edx -- mid 
    // ecx -- current
    // To save values
    pushl %ebx
    pushl %esi
    pushl %edi
    xorl %ecx, %ecx
    xorl %edx, %edx
loop:
    movw (%ebx, %ecx, 2), %ax
    cmpw %di, %ax
    jle swapper

    incl %ecx
    jmp check_end

swapper:
    pushl %edi
    movw (%ebx, %ecx, 2), %ax
    movw (%ebx, %edx, 2), %di
    movw %di, (%ebx, %ecx, 2)
    movw %ax, (%ebx, %edx, 2)
    popl %edi
    incl %edx
    incl %ecx
    jmp check_end

check_end:
    cmp %esi, %ecx
    jl loop
    pop %edi
    pop %esi
    pop %ebx
    ret
