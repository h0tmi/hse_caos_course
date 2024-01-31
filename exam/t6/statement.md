### Problem exam-t6: exam/tests/generated/test-06-sym

Дана единица трансляции на языке Си:

    
    
    int var0 = 0;
    int var1 = 1;
    int var;
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
    

Выберите символы, которые будут не определены в соответствующем объектном файле (то есть должны быть
определены в других объектных файлах, чтобы компоновка прошла успешно):

1) `var`

2) `evar`

3) `foo`

4) `sum`

5) `bar`

6) `function`

7) `fun0`

8) `fun`

### Notes

Внимание! Выпишите номера ответов через пробел в произвольном порядке.

Если вы считаете что верны ответы 1, 3 и 5 то введите 1 3 5

