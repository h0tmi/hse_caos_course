#include <stdint.h>
#include <stdio.h>

int main(void) {
    int a, b, n;
    if (scanf("%d %d %d", &a, &b, &n) != 3) {
        return 1;
    }
    printf("%*c ", n, ' ');
    for (int i = a; i < b; ++i) {
        if (i + 1 != b) {
            printf("%*d ", n, i);
        } else {
            printf("%*d", n, i);
        }
    }
    printf("\n");
    for (int64_t i = a; i < b; ++i) {
        printf("%*lld ", n, i);
        for (int64_t j = a; j < b; ++j) {
            if (j + 1 != b) {
                printf("%*lld ", n, i * j);
            } else {
                printf("%*lld", n, i * j);
            }
        }
        printf("\n");
    }
    return 0;
}
