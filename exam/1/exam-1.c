#include <math.h>
#include <stdio.h>
#include <stdlib.h>

union U {
    float value;
    int representation;
};

enum {
    SIGN_B = 1,
    EXP_B = 8,
    MANT_B = 23,
    MASK1 = 0b11100000000000000000000,
    MASK2 = 0b11000000000000000000000,
    MASK3 = 0b10000000000000000000000,
    MASK = 0b11111111111111111111111,
    T255 = 255,
    T254 = 254
};

// enum { SIGN = 31, EXP = 23, FRAC = 8, INF = 255 };

void div_div_div(float *arg) {
    union U u;
    u.value = *arg;

    unsigned sign = u.representation;
    sign >>= (EXP_B + MANT_B);
    unsigned mant = u.representation;
    mant = mant << (EXP_B + SIGN_B) >> (EXP_B + SIGN_B);
    unsigned exp = u.representation;
    exp = exp << SIGN_B >> (SIGN_B + MANT_B);

    sign = 1;
    if (exp <= 2) {
        *arg = 0;
        return;
    }
    exp -= 2;

    u.representation = (sign << (MANT_B + EXP_B)) | (exp << MANT_B) | mant;

    *arg = u.value;
}

// int main() {
//     float num;
//     while (scanf("%f", &num) != 0) {
//         div_div_div(&num);
//         printf("%f\n", num);
//     }
// }
