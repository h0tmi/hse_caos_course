#include <stdio.h>

extern void okay(double x, double y, double *r);

int main() {
    double x = 4.0;
    double y = 3.0;
    double result;

    okay(x, y, &result);

    printf("sqrt(%f^4 + %f^4) = %f\n", x, y, result);

    return 0;
}

