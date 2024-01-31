#include <stdio.h>

extern float okay(float x, float y, float z);

int main() {
    float x1 = 16.0, y1 = 3.0, z1 = 10.0;
    float result1 = okay(x1, y1, z1);
    printf("Result 1: %f\n", result1);

    float x2 = 0.0, y2 = 3.0, z2 = 10.0;
    float result2 = okay(x2, y2, z2);
    printf("Result 2: %f\n", result2);

    return 0;
}
