#include <bits/floatn-common.h>
#include <complex.h>
#include <stdint.h>
#include <stdio.h>

enum {
    MEGA_SUPER_MASK_ZAVALOV_I_LOVE_NOSITEL = 0xff000000,
};

int as_float(unsigned int value) {
    if (!value) {
        return 1;
    }
    while ((value & 1) == 0) {
        value >>= 1;
    }
    return !(value & MEGA_SUPER_MASK_ZAVALOV_I_LOVE_NOSITEL);
}

int main() {
    unsigned int num;
    while (scanf("%u", &num) == 1) {
        printf("%u\n", as_float(num));
    }
    return 0;
}
