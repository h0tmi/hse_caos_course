#include <stdio.h>
#include <string.h>

void fill_buffer(char *buf);

int main(int argc, char **argv) {
    char input[64] = "";
    char output[64] = "Buffer is incorrect";
    fill_buffer(input);
    printf("%s\n", output);
}
