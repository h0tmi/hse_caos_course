#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t (*sumfunc_t)(void);

char SUBPROGRAM[] = {0xb8, 0x00, 0x00, 0x00, 0x00, 0xc3};

sumfunc_t generate(void *buf, size_t bufsize, uint32_t *array, size_t size) {
    uint32_t sum;
    sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    for (size_t i = 0; i < 6; ++i) {
        ((char *)buf)[i] = SUBPROGRAM[i];
    }

    *(uint32_t *)(&((char *)buf)[1]) = sum;
    return (sumfunc_t)buf;
}

int main() {
    size_t sz = 0;
    char buf[10];
    uint32_t nums[5] = {1, 2, 3, -4};

    sumfunc_t gened_f = generate(buf, sz, nums, 4);

    printf("%d", gened_f());

    return 0;
}
