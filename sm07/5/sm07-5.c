#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t (*sumfunc_t)(void);

sumfunc_t generate(void *buf, size_t bufsize, uint32_t *array, size_t size) {
    uint32_t ans = 0;

    for (size_t i = 0; i < size; ++i) {
        ans += array[i];
    }

    char *ch_buf = (char *)buf;

    ch_buf[0] = 0xb8;
    ch_buf[1] = 0x00;
    ch_buf[2] = 0x00;
    ch_buf[3] = 0x00;
    ch_buf[4] = 0x00;
    ch_buf[5] = 0xc3;

    *(uint32_t *)(&ch_buf[1]) = ans;

    return buf;
}

int main() {
    size_t sz = 0;
    char buf[10];
    uint32_t nums[5] = {1, 2, 3, -4};

    sumfunc_t gened_f = generate(buf, sz, nums, 4);

    printf("%d", gened_f());

    return 0;
}
