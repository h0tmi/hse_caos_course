|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem sm03-4: asm/data-structures/list-reverse

Напишите подпрограмму list_reverse, которая разворачивает односвязный список. На проверку следует
сдать только файл с подпрограммой, без функции main.

Элемент списка хранится в памяти в виде трёх подряд идущих 32-битных машинных слов: (1-2)
произвольные 32-битные данные, (3) адрес следующего элемента списка или 0. В программе определена
глобальная переменная head, в которой хранится адрес начала списка. Подпрограмма должна развернуть
список inplace и записать в head новый адрес его начала.

Програма будет скомпилирована со следующей функцией main:

    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    
    struct elt {
        uint32_t a;
        uint32_t b;
        struct elt *next;
    };
    
    struct elt *head;
    void list_reverse();
    
    int main() {
        uint32_t x;
        while (scanf("%u", 	&x) == 1) {
            struct elt* elt = calloc(sizeof(struct elt), 1);
            elt->a = x;
            elt->b = x/2;
            elt->next = head;
            head = elt;
        }
        list_reverse();
        while (head) {
            printf("%u %u\n", head->a, head->b);
            head = head->next;
        }
    }
            

### Examples

#### Input

    
    
    1
    2
    3
    

#### Output

    
    
    1 0
    2 1
    3 1
    

