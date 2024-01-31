#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

size_t next(int fd, int offset, char ch) {
    size_t res;
    lseek(fd, offset, SEEK_SET);
    while (1) {
        char curr;
        uint32_t next;
        res = read(fd, &curr, 1);
        if (res < 0) {
            exit(EXIT_FAILURE);
        }

        res = read(fd, &next, 4);
        if (res < 0) {
            exit(EXIT_FAILURE);
        }

        if (curr == '\x0' && next == 0) {
            exit(EXIT_FAILURE);
        }

        if (curr == ch) {
            return next;
        }
    }
}

void try_to_find(int fd, int id, int offset, char *str) {
    while (id < strlen(str)) {
        offset = next(fd, offset, str[id++]);
    }
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        return EXIT_FAILURE;
    }

    try_to_find(fd, 0, 0, argv[2]);

    return EXIT_SUCCESS;
}
