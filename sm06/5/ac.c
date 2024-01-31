#include <stdint.h>
#include <stdlib.h>
#include <string.h>

enum {
    FIRST4 = 0b00001111,
    SECOND4 = 0b11110000,
    FIRST = 0b00000001,
    SECOND = 0b00000010,
    THIRD = 0b00000100,
    FOURTH = 0b00001000,
};

void encode(const void *data, void *encoded, size_t n) {
    const unsigned char *src = (const unsigned char *)data;
    unsigned char *dest = (unsigned char *)encoded;

    for (size_t i = 0; i < n; ++i) {
        unsigned char value = src[i];
        unsigned char f_v = (value & FIRST4);
        unsigned char s_v = (value & SECOND4) >> 4;
        unsigned char code = 0;

        code |= (f_v & FIRST) ^ ((f_v & SECOND) >> 1);
        code <<= 1;
        code |= ((f_v & THIRD) >> 2) ^ ((f_v & FOURTH) >> 3);
        code <<= 1;
        code |= (f_v & FIRST) ^ ((f_v & THIRD) >> 2);
        code <<= 1;
        code |= ((f_v & SECOND) >> 1) ^ ((f_v & FOURTH) >> 3);
        code <<= 1;

        code |= (s_v & FIRST) ^ ((s_v & SECOND) >> 1);
        code <<= 1;
        code |= ((s_v & THIRD) >> 2) ^ ((s_v & FOURTH) >> 3);
        code <<= 1;
        code |= (s_v & FIRST) ^ ((s_v & THIRD) >> 2);
        code <<= 1;
        code |= ((s_v & SECOND) >> 1) ^ ((s_v & FOURTH) >> 3);
        dest[i * 2] = value;
        dest[i * 2 + 1] = code;
    }
}

void decode(const void *encoded, void *data, size_t n) {
    const unsigned char *src = (const unsigned char *)encoded;
    unsigned char *dest = (unsigned char *)data;
    int was_mastake = 0;

    for (size_t i = 0; i < n; ++i) {
        unsigned char value = src[i * 2];
        if (was_mastake == 0) {
            unsigned char code = src[i * 2 + 1];
            unsigned char f_v = (value & FIRST4);
            unsigned char s_v = (value & SECOND4) >> 4;

            unsigned char f_c = (code & SECOND4) >> 4;
            unsigned char s_c = (code & FIRST4);
            if (((FIRST & f_c) ^ (FIRST & (f_c >> 1)) ^ (FIRST & (f_c >> 2)) ^
                 (FIRST & (f_c >> 3))) == 0) {
                if (((f_v & FIRST) ^ ((f_v & SECOND) >> 1)) !=
                        (FIRST & (f_c >> 3)) &&
                    (((f_v & SECOND) >> 1) ^ ((f_v & FOURTH) >> 3)) !=
                        (FIRST & f_c)) {
                    was_mastake = 1;
                    f_v ^= (FIRST) << 1;
                }
                if ((((f_v & THIRD) >> 2) ^ ((f_v & FOURTH) >> 3)) !=
                        (FIRST & (f_c >> 2)) &&
                    (((f_v & SECOND) >> 1) ^ ((f_v & FOURTH) >> 3)) !=
                        (FIRST & f_c)) {
                    was_mastake = 1;
                    f_v ^= (FIRST) << 3;
                }
                if ((((f_v & FIRST)) ^ ((f_v & THIRD) >> 2)) !=
                        (FIRST & (f_c >> 1)) &&
                    (((f_v & THIRD) >> 2) ^ ((f_v & FOURTH) >> 3)) !=
                        (FIRST & (f_c >> 2))) {
                    was_mastake = 1;
                    f_v ^= (FIRST) << 2;
                }
                if (((f_v & FIRST) ^ ((f_v & SECOND) >> 1)) !=
                        (FIRST & (f_c >> 3)) &&
                    (((f_v & FIRST)) ^ ((f_v & THIRD) >> 2)) !=
                        (FIRST & (f_c >> 1))) {
                    was_mastake = 1;
                    f_v ^= (FIRST);
                }
            }
            if (was_mastake == 0) {
                if (((FIRST & s_c) ^ (FIRST & (s_c >> 1)) ^
                     (FIRST & (s_c >> 2)) ^ (FIRST & (s_c >> 3))) == 0) {
                    if (((s_v & FIRST) ^ ((s_v & SECOND) >> 1)) !=
                            (FIRST & (s_c >> 3)) &&
                        (((s_v & SECOND) >> 1) ^ ((s_v & FOURTH) >> 3)) !=
                            (FIRST & s_c)) {
                        was_mastake = 1;
                        s_v ^= (FIRST) << 1;
                    }
                    if ((((s_v & THIRD) >> 2) ^ ((s_v & FOURTH) >> 3)) !=
                            (FIRST & (s_c >> 2)) &&
                        (((s_v & SECOND) >> 1) ^ ((s_v & FOURTH) >> 3)) !=
                            (FIRST & s_c)) {
                        was_mastake = 1;
                        s_v ^= (FIRST) << 3;
                    }
                    if ((((s_v & FIRST)) ^ ((s_v & THIRD) >> 2)) !=
                            (FIRST & (s_c >> 1)) &&
                        (((s_v & THIRD) >> 2) ^ ((s_v & FOURTH) >> 3)) !=
                            (FIRST & (s_c >> 2))) {
                        was_mastake = 1;
                        s_v ^= (FIRST) << 2;
                    }
                    if (((s_v & FIRST) ^ ((s_v & SECOND) >> 1)) !=
                            (FIRST & (s_c >> 3)) &&
                        (((s_v & FIRST)) ^ ((s_v & THIRD) >> 2)) !=
                            (FIRST & (s_c >> 1))) {
                        was_mastake = 1;
                        s_v ^= (FIRST);
                    }
                }
            }
            value = f_v + (s_v << 4);
        }
        dest[i] = value;
    }
}
