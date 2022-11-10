#include <unistd.h>

void mx_printstr(const char *s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    write(1, s, len);
}
