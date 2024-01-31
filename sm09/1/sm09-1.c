#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum {
    BUF_SIZE = 4096,
    CONSTM1 = -1,
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

// int main() {
//     int fd = open("example.txt", O_RDONLY);
//     if (fd == -1) {
//         return EXIT_FAILURE;
//     }
//
//     struct FileContent content = read_file(fd);
//
//     if (content.size == -1) {
//         return EXIT_FAILURE;
//     } else {
//         free(content.data);
//     }
//
//     close(fd);
//
//     return EXIT_SUCCESS;
// }
