#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int n_tu(int number, int count) {
    int result = 1;
    while (count-- > 0) {
        result *= number;
    }

    return result;
}

void float_to_string(float f, char r[]) {
    long long int length, length2, i, number, position, sign;
    float number2;

    sign = -1;  // -1 == positive number
    if (f < 0) {
        sign = '-';
        f *= -1;
    }

    number2 = f;
    number = f;
    length = 0;   // Size of decimal part
    length2 = 0;  // Size of tenth

    /* Calculate length2 tenth part */
    while ((number2 - (float)number) != 0.0 &&
           !((number2 - (float)number) < 0.0)) {
        number2 = f * (n_tu(10.0, length2 + 1));
        number = number2;

        length2++;
    }

    /* Calculate length decimal part */
    for (length = (f > 1) ? 0 : 1; f > 1; length++) {
        f /= 10;
    }

    position = length;
    length = length + 1 + length2;
    number = number2;
    if (sign == '-') {
        length++;
        position++;
    }

    for (i = length; i >= 0; i--) {
        if (i == (length)) {
            r[i] = '\0';
        } else if (i == (position)) {
            r[i] = '.';
        } else if (sign == '-' && i == 0) {
            r[i] = '-';
        } else {
            r[i] = (number % 10) + '0';
            number /= 10;
        }
    }
}

int main(int argc, char *argv[]) {
    uint32_t p, q, n;
    if (scanf("%u%u%u", &p, &q, &n) != 3) {
        return EXIT_FAILURE;
    }

    float p1 = (float)p;
    float q1 = (float)q;

    float ans = p1 / q1;

    char arr[1000000] = {0};

    float_to_string(ans, arr);

    // for (size_t h = g; h < 100000; ++h) {
    //     arr[h] = '0';
    // }

    for (size_t i = 0; i < 100000; ++i) {
        if (arr[i] == '.') {
            printf(".");
            for (size_t j = 0; j < n; ++j) {
                if (!printf("%c", arr[i + 1 + j])) {
                    printf("0");
                } 
            }
            return EXIT_SUCCESS;
        } else {
            printf("%c", arr[i]);
        }
    }

    return EXIT_SUCCESS;
}
