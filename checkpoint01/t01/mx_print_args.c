#include <unistd.h>

static void mx_printstr(const char *s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    write(1, s, len);
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printstr("\n");
    }
}
