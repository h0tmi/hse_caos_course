#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum {
    BUF_SIZE = 4096,
    CONSTM1 = -1,
    INFTY = 8,
};

struct FileContent {
    ssize_t size;
    char *data;
};

void free_mem(struct FileContent *fc, char *buffer) {
    if (buffer) {
        free(buffer);
    }
    if (fc->data) {
        free(fc->data);
        fc->data = NULL;
    }
    fc->size = CONSTM1;
}

struct FileContent read_file(int fd) {
    struct FileContent result;
    ssize_t summed_sz = 0;
    ssize_t cap = BUF_SIZE;
    ssize_t read_bytes;

    result.size = CONSTM1;
    result.data = NULL;

    char *buffer = NULL;

    buffer = realloc(buffer, cap);
    if (!buffer) {
        free(buffer);
        return result;
    }

    result.data = realloc(result.data, BUF_SIZE);
    if (result.data == NULL) {
        free_mem(&result, buffer);
        return result;
    }

    while ((read_bytes = read(fd, buffer, sizeof(buffer))) > 0) {
        if (summed_sz + read_bytes + 1 > cap) {
            cap = cap * 2;
            char *new_data = realloc(result.data, cap * sizeof(*new_data));

            if (!new_data) {
                free_mem(&result, buffer);
                return result;
            }

            result.data = new_data;
        }
        for (ssize_t i = 0; i < read_bytes; ++i) {
            result.data[summed_sz + i] = buffer[i];
        }

        summed_sz += read_bytes;
    }

    if (read_bytes < 0) {
        free_mem(&result, buffer);
        return result;
    }

    result.size = summed_sz;
    result.data[summed_sz] = '\0';

    free(buffer);

    return result;
}

struct FileWriteState {
    int fd;
    unsigned char *buf;
    int bufsize;
    int cur_cnt;
};

struct FileWriteState *stout;

void flush(struct FileWriteState *out) {
    asm volatile("mov $4, %%eax \n"
                 "int $0x80 \n"
                 :
                 : "b"(out->fd), "c"(out->buf), "d"(out->cur_cnt)
                 : "eax");
    out->cur_cnt = 0;
}

void writechar(int c, struct FileWriteState *out) {
    out->buf[out->cur_cnt++] = c;
    if (out->bufsize == out->cur_cnt) {
        flush(out);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        exit(EXIT_FAILURE);
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    int32_t mod = atoi(argv[3]);

    int input = open(input_filename, O_RDONLY);
    if (!input) {
        exit(EXIT_FAILURE);
    }

    int output =
        open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
    if (!output) {
        close(input);
        exit(EXIT_FAILURE);
    }

    static unsigned char buf[BUF_SIZE];
    struct FileWriteState st = {output, &buf[0], BUF_SIZE, 0};
    stout = &st;

    struct FileContent fc = read_file(input);

    printf("%zd", fc.size);

    for (int64_t i = 0; i < fc.size; ++i) {
        for (int64_t j = 0; j < INFTY; ++j) {
            if ((fc.data[i] >> j) & 1) {
                int64_t sum1 = 0;
                int64_t sum2 = 0;
                int64_t sum3 = 0;
                sum1 = (i * INFTY + j + 1);
                sum2 = 1 + (i * INFTY + j + 1);
                sum3 = 2 * (i * INFTY + j + 1) + 1;

                if (sum2 & 1LL) {
                    sum1 /= 2LL;
                } else {
                    sum2 /= 2LL;
                }

                if (sum1 % 3LL == 0LL) {
                    sum1 /= 3LL;
                } else if (sum2 % 3LL == 0LL) {
                    sum2 /= 3LL;
                } else {
                    sum3 /= 3LL;
                }

                int32_t sumn = (((sum1 * sum2) % mod) * sum3) % mod;

                char *outs = (char *)&sumn;
                writechar(outs[0], stout);
                writechar(outs[1], stout);
                writechar(outs[2], stout);
                writechar(outs[3], stout);
            }
        }
    }
    flush(stout);

    close(input);
    close(output);

    return 0;
}
