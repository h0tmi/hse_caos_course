#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
enum {
    H0 = 0b0000000,
    H1 = 0b0000111,
    H2 = 0b0011001,
    H3 = 0b0011110,
    H4 = 0b0101010,
    H5 = 0b0101101,
    H6 = 0b0110011,
    H7 = 0b0110100,
    H8 = 0b1001011,
    H9 = 0b1001100,
    H10 = 0b1010010,
    H11 = 0b1010101,
    H12 = 0b1100001,
    H13 = 0b1100110,
    H14 = 0b1111000,
    H15 = 0b1111111,
    BITS4 = 0xf,
    SIXTEEN = 16,
};
 
static const unsigned char PRECALCULATED_HAMMING[SIXTEEN] = {
    H0, H1, H2, H3, H4, H5, H6, H7, H8, H9, H10, H11, H12, H13, H14, H15,
};
 
void encode(const void *data, void *encoded, size_t n) {
    const unsigned char *const DATA_CHAR = data;
    unsigned char *const ENCODED_CHAR = encoded;
    for (int i = 0; i < n; ++i) {
        ENCODED_CHAR[i << 1] = PRECALCULATED_HAMMING[DATA_CHAR[i] & BITS4];
        ENCODED_CHAR[(i << 1) + 1] = PRECALCULATED_HAMMING[DATA_CHAR[i] >> 4];
    }
}
 
enum {
    C0 = 0,
    C1 = 0,
    C2 = 0,
    C3 = 1,
    C4 = 0,
    C5 = 1,
    C6 = 1,
    C7 = 1,
    C8 = 0,
    C9 = 2,
    C10 = 4,
    C11 = 8,
    C12 = 9,
    C13 = 5,
    C14 = 3,
    C15 = 1,
    C16 = 0,
    C17 = 2,
    C18 = 10,
    C19 = 6,
    C20 = 7,
    C21 = 11,
    C22 = 3,
    C23 = 1,
    C24 = 2,
    C25 = 2,
    C26 = 3,
    C27 = 2,
    C28 = 3,
    C29 = 2,
    C30 = 3,
    C31 = 3,
    C32 = 0,
    C33 = 12,
    C34 = 4,
    C35 = 6,
    C36 = 7,
    C37 = 5,
    C38 = 13,
    C39 = 1,
    C40 = 4,
    C41 = 5,
    C42 = 4,
    C43 = 4,
    C44 = 5,
    C45 = 5,
    C46 = 4,
    C47 = 5,
    C48 = 7,
    C49 = 6,
    C50 = 6,
    C51 = 6,
    C52 = 7,
    C53 = 7,
    C54 = 7,
    C55 = 6,
    C56 = 14,
    C57 = 2,
    C58 = 4,
    C59 = 6,
    C60 = 7,
    C61 = 5,
    C62 = 3,
    C63 = 15,
    C64 = 0,
    C65 = 12,
    C66 = 10,
    C67 = 8,
    C68 = 9,
    C69 = 11,
    C70 = 13,
    C71 = 1,
    C72 = 9,
    C73 = 8,
    C74 = 8,
    C75 = 8,
    C76 = 9,
    C77 = 9,
    C78 = 9,
    C79 = 8,
    C80 = 10,
    C81 = 11,
    C82 = 10,
    C83 = 10,
    C84 = 11,
    C85 = 11,
    C86 = 10,
    C87 = 11,
    C88 = 14,
    C89 = 2,
    C90 = 10,
    C91 = 8,
    C92 = 9,
    C93 = 11,
    C94 = 3,
    C95 = 15,
    C96 = 12,
    C97 = 12,
    C98 = 13,
    C99 = 12,
    C100 = 13,
    C101 = 12,
    C102 = 13,
    C103 = 13,
    C104 = 14,
    C105 = 12,
    C106 = 4,
    C107 = 8,
    C108 = 9,
    C109 = 5,
    C110 = 13,
    C111 = 15,
    C112 = 14,
    C113 = 12,
    C114 = 10,
    C115 = 6,
    C116 = 7,
    C117 = 11,
    C118 = 13,
    C119 = 15,
    C120 = 14,
    C121 = 14,
    C122 = 14,
    C123 = 15,
    C124 = 14,
    C125 = 15,
    C126 = 15,
    C127 = 15,
    MAGIC128 = 128,
};
 
static const unsigned char REVERSED_HAMMING[MAGIC128] = {
    C0,   C1,   C2,   C3,   C4,   C5,   C6,   C7,   C8,   C9,   C10,  C11,
    C12,  C13,  C14,  C15,  C16,  C17,  C18,  C19,  C20,  C21,  C22,  C23,
    C24,  C25,  C26,  C27,  C28,  C29,  C30,  C31,  C32,  C33,  C34,  C35,
    C36,  C37,  C38,  C39,  C40,  C41,  C42,  C43,  C44,  C45,  C46,  C47,
    C48,  C49,  C50,  C51,  C52,  C53,  C54,  C55,  C56,  C57,  C58,  C59,
    C60,  C61,  C62,  C63,  C64,  C65,  C66,  C67,  C68,  C69,  C70,  C71,
    C72,  C73,  C74,  C75,  C76,  C77,  C78,  C79,  C80,  C81,  C82,  C83,
    C84,  C85,  C86,  C87,  C88,  C89,  C90,  C91,  C92,  C93,  C94,  C95,
    C96,  C97,  C98,  C99,  C100, C101, C102, C103, C104, C105, C106, C107,
    C108, C109, C110, C111, C112, C113, C114, C115, C116, C117, C118, C119,
    C120, C121, C122, C123, C124, C125, C126, C127,
};
 
void decode(const void *encoded, void *data, size_t n) {
    const unsigned char *const ENCODED_CHAR = encoded;
    unsigned char *const DATA_CHAR = data;
    for (int i = 0; i < n; ++i) {
        DATA_CHAR[i] = REVERSED_HAMMING[ENCODED_CHAR[i << 1] & 0b1111111] |
                       REVERSED_HAMMING[ENCODED_CHAR[(i << 1) + 1] & 0b1111111]
                           << 4;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Ваш код с функциями encode и decode

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
    uint8_t inputData[dataSize] = {0xAA, 0xBB, 0xCC, 0xDD};

    // Создаем буферы для закодированных и декодированных данных
    uint8_t encodedData[encodedSize] = {0};
    uint8_t decodedData[dataSize] = {0};

    // Тест на кодирование
    encode(inputData, encodedData, dataSize);

    printf("Encoded data: ");
    print_hex(encodedData, encodedSize);

    // Добавим некоторые проверки, чтобы убедиться, что данные были закодированы
    // Например, проверим, что первый и третий байты отличаются от исходных данных
    if (encodedData[0] == inputData[0] || encodedData[2] == inputData[2]) {
        printf("Encoding test failed!\n");
        return EXIT_FAILURE;
    }

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
