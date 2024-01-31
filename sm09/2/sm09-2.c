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
