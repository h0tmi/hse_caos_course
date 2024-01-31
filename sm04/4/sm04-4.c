void normalize_path(char *buf) {
    char *new_buf = buf;
    char prev = '\0';
    while ((unsigned char)*buf != '\0') {
        if (!(*buf == '/' && prev == '/')) {
            *new_buf = *buf;
            ++new_buf;
        }
        prev = (unsigned char)*buf;
        ++buf;
    }
    *new_buf = '\0';
}
