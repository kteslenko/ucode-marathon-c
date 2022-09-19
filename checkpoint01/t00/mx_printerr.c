#include <unistd.h>

void mx_printerr(const char *s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    write(2, s, len);
}
