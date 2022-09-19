#include <unistd.h>

static void printint(int n) {
    int pow = 1;

    for (int i = n; i >= 10; i /= 10) {
        pow *= 10;
    }
    
    while (pow != 0) {
        int c = n / pow % 10 + 48;
        write(1, &c, 1);
        pow /= 10;
    }
}

static void printstr(const char *s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    write(1, s, len);
}

int main(int argc, char *argv[]) {
    printstr(argv[0]);
    printstr("\n");
    printint(argc);
    printstr("\n");
}
