### Problem kr01-t4: tests/kr1/commonx86

Выберите верные утверждения о программах на языке ассемблера x86-32 в синтаксисе AT&T

1) вместо инструкции можно записать байтами соответствующий машинный код (например, `.byte 0x90`
вместо `nop`)

2) Директива `.int 42, 43` резервирует 8 байт памяти и аннотирует их типом `int` (то есть в этой
памяти в дальнейшем можно хранить только 4-байтовые целые числа)

3) Директива `.global` помечает участок памяти как глобально доступный (то есть к нему можно
осуществлять read/write доступ из любой единицы трансляции)

4) В одном исходном файле можно несколько раз использовать директивы переключения между секциями
(`.text`, `.data` и т. д.): при формировании объектного файла ассемблер соберёт содержимое каждой
секции в том порядке, как оно записано в программе

5) Директива `.asciz` позволяет зарезервировать память под нуль-терминированную строку и проверяет,
что символы в строке входят в кодировку ASCII

### Notes

Внимание! Выпишите номера ответов через пробел в произвольном порядке.

Если вы считаете что верны ответы 1, 3 и 5 то введите 1 3 5

