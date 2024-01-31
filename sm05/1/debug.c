
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// DELETE BELOW
struct Block {
    uint32_t size;
    struct Block *next;
};

struct Block *freelist = NULL;

// DELETE ABOVE

size_t align4(size_t size) {
    return (size + 3) & ~3;
}

void *alloc_mem(size_t size) {
    struct Block *current_block = freelist;
    struct Block *prev_block = NULL;
    while (current_block) {
        if (size <= current_block->size) {
            if (prev_block) {
                prev_block->next = current_block->next;
            } else {
                freelist = freelist->next;
            }
            return (void *)((char *)current_block + 4);
        }
        prev_block = current_block;
        current_block = current_block->next;
    }

    size_t new_size = align4(size);
    if (new_size < size) {
        return NULL;
    }
    new_size += 4;
    if (new_size < size) {
        return NULL;
    }

    if (new_size > INTPTR_MAX || new_size > UINT32_MAX) {
        return NULL;
    }
    void *new_block = sbrk(new_size);
    if (new_block == (void *)(-1)) {
        return NULL;
    }

    ((struct Block *)new_block)->size = new_size;

    return (void *)((char *)new_block + 4);
}

void free_mem(void *ptr) {
    if (!ptr) {
        return;
    }
    struct Block *block = (struct Block *)((char *)ptr - 4);
    block->next = freelist;
    freelist = block;
}

// DELETE BELOW

int main() {
    void *ptr = alloc_mem(14);
    char *str = strcpy(ptr, "Hello world12");
    printf("%s\n", str);
    free_mem(ptr);
    ptr = alloc_mem(13);
    str = strcpy(ptr, "Hello pidor12");
    printf("%s\n", str);
    free_mem(ptr);
    ptr = alloc_mem(100);
    str = strcpy(ptr, "Hello pidor");
    printf("%s\n", str);
    free_mem(ptr);
    ptr = alloc_mem(101);
    str = strcpy(ptr, "Hello pidor");
    printf("%s\n", str);
    free_mem(ptr);
    if (freelist == NULL) {
        printf("DOLBAEB");
    }
    while (freelist) {
        printf("%u ", freelist->size);
        printf("%s ", (char *)freelist->next);
        freelist = freelist->next;
    }
    return 0;
}
