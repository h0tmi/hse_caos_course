|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem exam-5: exam/trie

Дано префиксное дерево (trie), записанное в файл на диске. Корень дерева записан в начале файла.
Каждая вершина дерева записана в виде массива ссылок на дочерние вершины. Каждая ссылка записана
так:

1. (1 байт) символ ASCII
2. (4 байта) смещение от начала файла до начала дочерней вершины дерева в хостовом представлении

В конце каждого массива ссылок записана ссылка с нулевым символом.

Программа запускается с двумя аргументами: `./myprog TRIE_FILE STRING`. Она должна завершиться
успешно, если строка STRING есть в префиксном дереве, и неуспешно (с кодом 1) в противном случае.

Выводить ничего не нужно.

Гарантируется, что размер файла не превышает 4ГБ, а смещения вершин не выходят за границу файла.

Пример префиксного дерева, в котором имеются строки "", "a", "ab":

    
    
    61 0a 00 00 00  00 00 00 00 00
    62 14 00 00 00  00 00 00 00 00
    00 00 00 00 00

