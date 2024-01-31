#include <math.h>
#include <stdio.h>

#define FOURTHIRDS 1.33333F
#define ONETHIRD 0.33333F

enum {
    INFTY = 0x7F800000,
    MAGIC_CONST = 0x54a21d2a,
    SIZE = 1000,
};

float fast_reverse_cube(float number) {
    float x3, y;

    x3 = number * ONETHIRD;

    union {
        int repres;
        float f;
    } u;

    u.f = number;
    u.repres = MAGIC_CONST - u.repres / 3;
    y = u.f;

    y = y * (FOURTHIRDS - x3 * y * y * y);
    y = y * (FOURTHIRDS - x3 * y * y * y);

    return y;
}

void fast_const_pow(float *arr, size_t size) {
    union {
        int repres;
        float infty;
    } u;

    u.repres = INFTY;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] != 0) {
            arr[i] = fast_reverse_cube(arr[i]);
        } else {
            arr[i] = u.infty;
        }
    }
}

int main() {
    float nums[SIZE];
    int sz = 0;
    while (scanf("%f", &nums[sz]) == 1) {
        sz++;
    }

    fast_const_pow(nums, sz);

    for (size_t i = 0; i < sz; ++i) {
        printf("%f ", nums[i]);
    }
    printf("\n");
    return 0;
}
