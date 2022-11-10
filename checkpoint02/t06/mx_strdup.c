#include <stdlib.h>

static int strlen(const char *str) {
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

static char *strnew(const int size) {
    char *str;

    if (size < 0) {
        return NULL;
    }

    str = malloc(size + 1);

    if (str == NULL) {
        return NULL;
    }

    for (int i = 0; i < size + 1; i++) {
        str[i] = '\0';
    }

    return str;
}

char *mx_strdup(const char *str) {
    char *new_str;
    int len;

    if (str == 0) {
        return 0;
    }

    len = strlen(str);
    new_str = strnew(len);

    if (new_str == 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        new_str[i] = str[i];
    }

    return new_str;
}
