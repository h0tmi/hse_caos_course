### Problem exam-t3: exam/tests/generated/test-03-ub

Выберите фрагменты кода на языке Си (стандарт C11), в которых может возникнуть undefined behavior:

1) `char x = 42; scanf("%d", &x);`

2) `int x = 42; short s = *(short *)&x;`

3) `char x = 42; printf("%d", x);`

4) `unsigned x = 1; x <<= 10;`

5) `unsigned x = 1; x <<= 15;`

6) `int x = 1; x <<= 10;`

7) `int x = 1; x <<= 15;`

8) `int x = 42; char s = *(char *)&x;`

### Notes

Внимание! Выпишите номера ответов через пробел в произвольном порядке.

Если вы считаете что верны ответы 1, 3 и 5 то введите 1 3 5

