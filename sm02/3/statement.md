|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem sm02-3: asm/algorithms/pivot-1

Напишите подпрограмму ‘partition’, которая в регистре EBX (RBX) принимает адрес начала массива arr
элементов типа int16_t, в регистре ESI их количество size (size > 1) и в регистре EDI знаковое
значение pivot. Гарантируется, что элемент, равный pivot, в массиве существует.

Перегруппируйте элементы массива таким образом, что в начале массива находятся элементы, для которых
выполняется условие arr[i] <= pivot, а в конце массива — arr[i] >= pivot.

То есть в итоговом массиве должен существовать такой индекс mid (0 <= mid < size) что arr[i] <=
pivot для любого i < mid и arr[i] >= pivot для любого i >= mid.

В регистре EDX верните mid.

Соблюдайте стандартные соглашения о сохранении/восстановлении регистров.

Например, если задан массив { 10 9 8 7 6 5 4 3 2 1 } и значение pivot == 5, возможным результатом
будет массив { 1 2 3 4 6 5 7 8 9 10 } и значение mid == 4.

Функцию вызова вашего кода из си можно взять
[тут](https://gist.github.com/ObjatieGroba/d7102f7fe80871f787e9b0321667fa52)
    .text
    .global main
main:
    call readi32
    movl %eax, %esi
    xor %edx, %edx
input:
    cmp %esi, %edx
    jge end_input

    call readi32
    movw %ax, x(, %edx, 2)

    incl %edx
    jmp input
end_input:
    movl $x, %ebx
    call readi32
    movl %eax, %edi
    call partition 
    movl $0, %edx
    //call output
    call finish
    .global x
.data
x:  .skip 2 * 100


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
    //movl %edx, %eax
    //call writei32
    ret

output:
    cmpl %esi, %edx
    jge end_output

    movw (%ebx, %edx, 2), %ax
    call writei32
    
    incl %edx
    jmp output
end_output:
 
