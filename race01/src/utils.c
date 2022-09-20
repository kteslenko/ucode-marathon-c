#include "../inc/header.h"

int ctod(char ch) {
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch == '?')
        return 0;
    return -1;
}

static bool match_signs(long number, const char *pattern) {
    if (number < 0) {
        return pattern[0] == '-';
    }
    return pattern[0] != '-';
}

bool matches(long number, const char *pattern) {
    if (!match_signs(number, pattern)) {
        return false;
    }

    if (pattern[0] == '-') {
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


