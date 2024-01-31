#include <stdio.h>
#include <stdlib.h>
 
void sort_by_abs(int16_t* x, int size);
 
int main() {
    int n;
    scanf("%d", &n);
    int16_t* arr = malloc(n * sizeof(int16_t));
    for (int i = 0; i < n; ++i) {
        scanf("%hd", &arr[i]);
    }
    sort_by_abs(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%hd ", arr[i]);
    }
    free(arr);
    return 0;
}
