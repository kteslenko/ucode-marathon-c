#include "header.h"

char *mx_strndup(const char *str, int n) {
    char *new_str;

    if (str == 0) {
        return 0;
    }

    new_str = mx_strnew(n);

    if (new_str == 0) {
        return 0;
    }

    return mx_strncpy(new_str, str, n);
}
