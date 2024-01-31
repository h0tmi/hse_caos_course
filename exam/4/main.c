#include <stddef.h>
#include <stdio.h>

size_t count(char *buf);

int main() {
    char *str = "1234";
    
    printf("%zu", count(str));
}
