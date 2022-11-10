#include <unistd.h>

static void printstr(const char *s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    write(1, s, len);
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        printstr(argv[i]);
        printstr("\n");
    }
}
