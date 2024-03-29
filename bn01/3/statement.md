### Problem bn01-3: asm/hacks/crackme

Для этого задания вам понадобится программа [`crackme`](https://caos2023.myltsev.ru/crackme),
скомпилированная под Linux i386. Программа при запуске ожидает на потоке стандартного ввода строку
(так называемый "флаг") и каким-то неизвестным вам методом проверяет, верен ли введенный флаг.

Вам нужно найти флаг, для которого программа выведет `Correct flag!`, и заслать его в качестве
решения задачи.

Для решения вам понадобится прочитать ассемблерный код программы. Для этого можно использовать
инструмент [`objdump`](https://linux.die.net/man/1/objdump), например: `objdump -d crackme`.
Существуют и другие, [более удобные
дизассемблеры](https://en.wikibooks.org/wiki/X86_Disassembly/Disassemblers_and_Decompilers#x86_Disassemblers).
Алиса рекомендует [самописный простой дизассемблер](https://github.com/purplesyringa/disas). Но если
хочется поиграться, можно попробовать воспользоваться IDA, Ghidra и другими.

Если вам вдруг захочется погуглить, как решать задания такого вида, в сообществе CTF они известны
как тип `reverse`. В какой-то момент, правда, все-таки придется подумать своей головой.

В качестве ответа сдайте флаг

