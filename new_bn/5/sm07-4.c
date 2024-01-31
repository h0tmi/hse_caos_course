#include <stdio.h>

enum {
    BITS16 = 16,
    MAGIC_CONST = 0xAAAB,
};

long divide_by_three(int num) {
    return ((((long)num * (long)MAGIC_CONST) >> BITS16) >> 1);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    printf("%ld\n", divide_by_three(n));
}
