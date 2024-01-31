#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(const void *data, void *encoded, size_t n) {

}

void decode(const void *encoded, void *data, size_t n) {

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
    uint8_t inputData[40] = {0xAA, 0xBB, 0xCC, 0xDD};

    // Создаем буферы для закодированных и декодированных данных
    uint8_t encodedData[40] = {0};
    uint8_t decodedData[40] = {0};

    printf("Source data: ");
    print_hex(inputData, dataSize);

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
