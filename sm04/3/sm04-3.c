int mystrcmp(const char *str1, const char *str2) {
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;
    }
    if (*str1 == '\0') {
        return -1;
    }
    if (*str2 == '\0') {
        return 1;
    }
    if ((unsigned char)*str1 < (unsigned char)*str2) {
        return -1;
    }
    if ((unsigned char)*str1 > (unsigned char)*str2) {
        return 1;
    }
    return mystrcmp(++str1, ++str2);
}
