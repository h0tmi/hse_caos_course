#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node {
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

void print_tree(int fd, int32_t root_idx, int is_root) {
    if (root_idx == 0 && !is_root) {
        return;
    }
    struct Node root;

    int r = pread(fd, &root, sizeof(root), sizeof(root) * root_idx);

    if (r != sizeof(root)) {
        exit(EXIT_FAILURE);
    }

    print_tree(fd, root.right_idx, 0);
    printf("%d ", root.key);
    print_tree(fd, root.left_idx, 0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        exit(EXIT_FAILURE);
    }

    print_tree(fd, 0, 1);
    printf("\n");

    close(fd);

    return 0;
}
