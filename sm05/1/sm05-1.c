#include <stdint.h>
#include <unistd.h>

struct Block {
    uint32_t size;
    struct Block *next;
};

extern struct Block *freelist;

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
            return (void *)((struct Block *)current_block + 1);
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

    return (void *)((struct Block *)new_block + 1);
}

void free_mem(void *ptr) {
    if (!ptr) {
        return;
    }
    struct Block *block = (struct Block *)(ptr)-1;
    block->next = freelist;
    freelist = block;
}
