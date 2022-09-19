#include "../inc/header.h"

int ctod(char ch) {
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch == '?')
        return 0;
    return -1;
}

bool matches(long number, const char *pattern) {
    if (pattern[0] == '-') {
        if (number >= 0) {
            return false;
        }
        number *= -1;
        pattern++;
    }

    for (int i = mx_strlen(pattern) - 1; i >= 0; i--) {
        if (pattern[i] != '?' && number % 10 != ctod(pattern[i])) {
            return false;
        }
        number /= 10;
    }

    return number == 0;
}

long lpow(long n, unsigned int pow) {
    long result = 1;

    for (unsigned int i = 0; i < pow; i++) {
        result *= n;
    }

    return result;
}
