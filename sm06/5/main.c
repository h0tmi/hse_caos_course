#include <stdint.h>
#include <stdio.h>
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
void print_ch_s(unsigned char a) {
    for (size_t i = 4; i < 8; i++) {
        printf("%d", !!((a << i) & 0x80));
    }
}
void print_ch(unsigned char a) {
    for (size_t i = 0; i < 8; i++) {
        printf("%d", !!((a << i) & 0x80));
    }
}

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
        printf("%c\n", code);
        dest[i * 2] = value;
        dest[i * 2 + 1] = code;

        /// DEBUG

        printf("Iter %zu; ", i);
        print_ch(value);
        printf(" ");
        print_ch(code);
        printf("\n");
        print_ch(f_v);
        printf(" ");
        print_ch(code & SECOND4);
        printf(" &&& ");
        print_ch(s_v);
        printf(" ");
        print_ch(code & FIRST4);
        printf("\n");
    }
}


void decode(const void *encoded, void *data, size_t n) {
    const unsigned char *src = (const unsigned char *)encoded;
    unsigned char *dest = (unsigned char *)data;
    int was_mastake = 0;

    for (size_t i = 0; i < n; ++i) {
        unsigned char value = src[i * 2];
        if (i == 1) {
            value ^= 0b00000001;
        }
        if (was_mastake == 0) {
            unsigned char code = src[i * 2 + 1];
            unsigned char f_v = (value & FIRST4);
            unsigned char s_v = (value & SECOND4) >> 4;

            unsigned char f_c = (code & SECOND4) >> 4;
            unsigned char s_c = (code & FIRST4);
            
            printf("Iter %zu; ", i);
            print_ch(value);
            printf(" ");
            print_ch(code);
            printf("\n");
            print_ch(f_v);
            printf(" ");
            print_ch((code & SECOND4) >> 4);
            printf(" &&& ");
            print_ch(s_v);
            printf(" ");
            print_ch(code & FIRST4);
            printf("\n");


            if (((FIRST & f_c) ^ (FIRST & (f_c >> 1)) ^ (FIRST & (f_c >> 2)) ^
                    (FIRST & (f_c >> 3))) ==
                0) {
                if (((f_v & FIRST) ^ ((f_v & SECOND) >> 1)) != (FIRST & (f_c >> 3)) && (((f_v & SECOND) >> 1) ^ ((f_v & FOURTH) >> 3)) != (FIRST & f_c)) {
                    printf("F + S\n");
                    was_mastake = 1;
                    f_v ^= (FIRST) << 1;
                }
                if ((((f_v & THIRD) >> 2)^ ((f_v & FOURTH) >> 3)) != (FIRST & (f_c >> 2)) && (((f_v & SECOND) >> 1) ^ ((f_v & FOURTH) >> 3)) != (FIRST & f_c)) {
                    printf("T + F\n");
                    was_mastake = 1;
                    f_v ^= (FIRST) << 3;
                }
                if ((((f_v & FIRST)) ^ ((f_v & THIRD) >> 2)) != (FIRST & (f_c >> 1)) && (((f_v & THIRD) >> 2)^ ((f_v & FOURTH) >> 3)) != (FIRST & (f_c >> 2))) {
                    printf("F + T\n");
                    was_mastake = 1;
                    f_v ^= (FIRST) << 2;
                }
                if (((f_v & FIRST) ^ ((f_v & SECOND) >> 1)) != (FIRST & (f_c >> 3)) && (((f_v & FIRST)) ^ ((f_v & THIRD) >> 2)) != (FIRST & (f_c >> 1))) {
                    printf("S + F\n");
                    was_mastake = 1;
                    f_v ^= (FIRST);
                }
            }
            if (((FIRST & s_c) ^ (FIRST & (s_c >> 1)) ^ (FIRST & (s_c >> 2)) ^
                    (FIRST & (s_c >> 3))) ==
                0) {
                if (((s_v & FIRST) ^ ((s_v & SECOND) >> 1)) != (FIRST & (s_c >> 3)) && (((s_v & SECOND) >> 1) ^ ((s_v & FOURTH) >> 3)) != (FIRST & s_c)) {
                    printf("F + S\n");
                    was_mastake = 1;
                    s_v ^= (FIRST) << 1;
                }
                if ((((s_v & THIRD) >> 2)^ ((s_v & FOURTH) >> 3)) != (FIRST & (s_c >> 2)) && (((s_v & SECOND) >> 1) ^ ((s_v & FOURTH) >> 3)) != (FIRST & s_c)) {
                    printf("T + F\n");
                    was_mastake = 1;
                    s_v ^= (FIRST) << 3;
                }
                if ((((s_v & FIRST)) ^ ((s_v & THIRD) >> 2)) != (FIRST & (s_c >> 1)) && (((s_v & THIRD) >> 2)^ ((s_v & FOURTH) >> 3)) != (FIRST & (s_c >> 2))) {
                    printf("F + T\n");
                    was_mastake = 1;
                    s_v ^= (FIRST) << 2;
                }
                if (((s_v & FIRST) ^ ((s_v & SECOND) >> 1)) != (FIRST & (s_c >> 3)) && (((s_v & FIRST)) ^ ((s_v & THIRD) >> 2)) != (FIRST & (s_c >> 1))) {
                    printf("S + F\n");
                    was_mastake = 1;
                    s_v ^= (FIRST);
                }
            }
           value = f_v + (s_v << 4);

            printf("Iter %zu; ", i);
            print_ch(value);
            printf(" ");
            print_ch(code);
            printf("\n");
            print_ch(f_v);
            printf(" ");
            print_ch((code & SECOND4) >> 4);
            printf(" &&& ");
            print_ch(s_v);
            printf(" ");
            print_ch(code & FIRST4);
            printf("\n");
        }

        dest[i] = value;
    }
}

void print_hex(const uint8_t *data, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

int main() {
    const size_t dataSize = 4;  // Размер входных данных
    const size_t encodedSize = 8;  // Размер закодированных данных

    // Создаем входные данные
    uint8_t inputData[60] = {0b10100011, 0xBC, 0xCC, 0xDD};

    // Создаем буферы для закодированных и декодированных данных
    uint8_t encodedData[120] = {0};
    uint8_t decodedData[60] = {0};

    // Тест на кодирование
    encode(inputData, encodedData, dataSize);

    printf("Encoded data: ");
    print_hex(encodedData, encodedSize);

    // Добавим некоторые проверки, чтобы убедиться, что данные были закодированы
    // Например, проверим, что первый и третий байты отличаются от исходных
    // данных if (encodedData[0] == inputData[0] || encodedData[2] ==
    // inputData[2]) {
    //     printf("Encoding test failed!\n");
    //     return EXIT_FAILURE;
    // }

    // Тест на декодирование
    decode(encodedData, decodedData, dataSize);

    printf("Decoded data: ");
    print_hex(decodedData, dataSize);

    // Проверяем, что декодированные данные совпадают с исходными
    if (memcmp(inputData, decodedData, dataSize) != 0) {
        printf("Decoding test failed!\n");
        return EXIT_FAILURE;
    }

    printf("All tests passed!\n");

    return EXIT_SUCCESS;
}
