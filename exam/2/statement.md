|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem exam-2: exam/gcc

Дана подпрограмма на языке ассемблера архитектуры x86:

    
    
    func:
    movl    4(%esp), %edx
    movl    8(%esp), %eax
    leal    (%edx,%eax,4), %eax
    movl    (%eax), %edx
    addl    4(%edx), %eax
    addl    12(%esp), %eax
    ret
    

Запишите ее на языке Си.

