#include "../inc/header.h"

static int count_unknown(const char *pattern) {
    int count = 0;

    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] == '?') {
            count++;
        }
    }

    return count;
}

t_number *parse_pattern(const char *pattern) {
    t_number *number = new_number(count_unknown(pattern));
    int unknown_idx = 0;
    long mult = 1;

    if (pattern[0] == '-') {
        mult = -1;
        pattern++;
    }

    for (int i = mx_strlen(pattern) - 1; i >= 0; i--) {
        if (pattern[i] == '?') {
            number->digits[unknown_idx] = mult < 0 ? 9 : 0;
            number->mults[unknown_idx] = mult;
            unknown_idx++;
        }
        number->pattern += ctod(pattern[i]) * mult;
        mult *= 10;
    }

    return number;
}
