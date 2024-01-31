#include <stdio.h>

int main() {
    unsigned a, b;
    if (scanf("%u %u", &a, &b) != 2) {
        return 1;
    }

    unsigned ans = 0;
    ans += a / 2;
    ans += b / 2;

    if (1 & a && 1 & b) {
        ++ans;
    }
    printf("%u\n", ans);
}
