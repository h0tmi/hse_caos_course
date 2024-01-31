### Problem exam-t5: exam/tests/generated/test-05-bss

Дана единица трансляции на языке Си:

    
    
    int var0 = 0;
    int var1 = 1;
    extern int evar;
    
    static int foo(int arg) {
        int sum = arg + evar;
        return sum;
    }
    
    int bar(int arg);
    
    void function(int arg) {
        int fun0 = 0;
        static int fun;
        fun0 = foo(arg) + bar(arg);
        fun = fun0 + arg;
    }
    

Выберите переменные, которые будут храниться в секции `.bss` соответствующего объектного файла:

1) `var0`

2) `var1`

3) `evar`

4) `sum`

5) `fun0`

6) `fun`

### Notes

Внимание! Выпишите номера ответов через пробел в произвольном порядке.

Если вы считаете что верны ответы 1, 3 и 5 то введите 1 3 5

