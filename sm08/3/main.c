#include <stdio.h>
 
void product(int n, const float *x, const float *y, float *result);
 
int main() {
    float cringe1[7] = {1., 2., 3., 4., 5., 6., 7.};
    float cringe2[7] = {1., 2., 3., 4., 5., 6., 7.};

    float res = 0;
 
    product(0, cringe1, cringe2, &res);
    printf("%f\n", res);
 
    product(1, cringe1, cringe2, &res);
    printf("%f\n", res);

    product(2, cringe1, cringe2, &res);
    printf("%f\n", res);

    product(4, cringe1, cringe2, &res);
    printf("%f\n", res);

    product(7, cringe1, cringe2, &res);
    printf("%f\n", res);

    float c1[7] = { 1.5, 3.5 };
    float c2[7] = {-3.5, -1.0};

    res = 0;
    product(2, c1, c2, &res);
    printf("%f\n", res);
    return 0;
}
