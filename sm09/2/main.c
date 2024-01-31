#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum {
    BUF_SIZE = 4096,
};

struct FileWriteState {
    int fd;
    unsigned char *buf;
    unsigned bufsize;
    unsigned cur_cnt;
};

static unsigned char buf[BUF_SIZE];
static struct FileWriteState st = {1, &buf[0], BUF_SIZE, 0};

struct FileWriteState *stout = &st;

void flush(struct FileWriteState *out) {
    if (!out) {
        return;
    }
    asm volatile("int $0x80 \n"
                 :
                 : "a"(4), "b"(out->fd), "c"(out->buf), "d"(out->cur_cnt)
                 :);
    out->cur_cnt = 0;
}

void writechar(int c, struct FileWriteState *out) {
    if (!out) {
        return;
    }
    out->buf[out->cur_cnt++] = c;
    if (out->bufsize == out->cur_cnt) {
        flush(out);
    }
}

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        writechar(c, stout);
    }
    flush(stout);
    return 0;
}

// int main()
// {
//     st->fd = 1; // Используем стандартный поток вывода
//     fileWriteState.bufsize = 0; // Изначально буфер пуст
//     stout = &fileWriteState;
//
//     // Тестирование функций
//     writechar('H', stout);
//     writechar('e', stout);
//     writechar('l', stout);
//     writechar('l', stout);
//     writechar('o', stout);
//
//     // Перед завершением программы вызываем flush
//     flush(stout);
//
//     return 0;
// }
//
