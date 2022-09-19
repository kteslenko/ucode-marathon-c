#include <stdlib.h>

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

static int num_len(unsigned long nbr) {
    int len = 1;

    for (unsigned long i = nbr; i >= 16; i /= 16) {
        len++;
    }

    return len;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    static const char* digits = "0123456789abcdef";
    int len = num_len(nbr);
    char *str = strnew(len);

    for (int i = len; i > 0; i--) {
        str[i - 1] = digits[nbr % 16];
        nbr /= 16;
    }

    return str;
}
