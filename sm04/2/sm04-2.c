#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

unsigned int fr(uint64_t value) {
    uint64_t fib1 = 1, fib2 = 1, res = 0, cnt = 0;
    while (fib2 <= value) {
        res = fib1 + fib2;
        fib1 = fib2;
        fib2 = res;
        cnt++;
    }
    return cnt;
}

int main() {
    uint64_t current_nubmer;

    while (scanf("%" SCNx64, (uint64_t *)&current_nubmer) == 1) {
        printf("%x ", fr(current_nubmer));
    }
    printf("\n");
    return 0;
}
