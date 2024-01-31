|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem bn01-2: asm/hacks/buffer-overflow

Напишите функцию `void fill_buffer(char *input)` заполняющую буффер так чтобы вывод программы
соответствовал примеру.

Ваша программа будет скомпилирована с указанным main.c:

    
    
    #include <stdio.h>
    #include <string.h>
    
    void fill_buffer(char * buf);
    
    int main(int argc, char **argv) {
        char input[64] = "";
        char output[64] = "Buffer is incorrect";
        fill_buffer(input);
        printf("%s\n", output);
    }
    

Ваша программа не должна использовать вспомогательных функций кроме функций из библиотеки string.h

Ваша программа не должна осуществлять ввод и вывод

### Examples

#### Input

#### Output

    
    
    Прошу соблюдать правила ВШЭ

