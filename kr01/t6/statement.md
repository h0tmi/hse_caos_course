### Problem kr01-t6: tests/kr1/linuxbuild

Выберите верные утверждения о сборке программ, написанных на языке Си для GNU/Linux на платформе
x86-32:

1) Компоновщик разрешает зависимости по символам между объектными файлами, учитывая имена и типы
символов (например, попытка объявить `extern int foo` в одной единице трансляции и определить `void
foo(void)` в другой единице трансляции приведёт к ошибке компоновки из-за несоответствия типов).

2) Функции или глобальной переменной `foo`, определённой в коде программы без использования
ключевого слова `static`, будет соответствовать глобальный символ `foo` в соответствующем объектном
файле.

3) Запись `const char* str = "hello";` в теле функции приведёт к тому, что в секции `.rodata`
объектного файла появится строка байт `hello\0`.

4) Запись `const char str[] = "hello";` в теле функции приведёт к тому, что в секции `.rodata`
объектного файла появится строка байт `hello\0`.

5) Автоматические переменные хранятся на стеке, и поэтому память для них резервируется в секции
`.stack` объектных и исполнимых файлов.

### Notes

Внимание! Выпишите номера ответов через пробел в произвольном порядке.

Если вы считаете что верны ответы 1, 3 и 5 то введите 1 3 5

