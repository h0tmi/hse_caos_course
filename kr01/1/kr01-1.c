#include <ctype.h>
#include <stdio.h>

void strip_spaces(char *buf) {
    char *new_buf = buf;
    char *old_buf = buf;
    char prev = '\0';
    while (isspace(*buf)) {
        ++buf;
    }
    while ((unsigned char)*buf != '\0') {
        if (!(isspace(*buf) && isspace(prev))) {
            if (isspace(*buf)) {
                *new_buf = ' ';
            } else {
                *new_buf = *buf;
            }
            ++new_buf;
        }
        prev = (unsigned char)*buf;
        ++buf;
    }
    if (new_buf > old_buf) {
        --new_buf;
        while (new_buf > old_buf && isspace(*new_buf)) {
            --new_buf;
        }
        ++new_buf;
    }
    *new_buf = '\0';
}

int main() {
    char str[] = "";
    strip_spaces(str);
    printf("%s", str);
}
