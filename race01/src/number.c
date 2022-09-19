#include "../inc/header.h"

int ntoi(t_number *number) {
    int result = number->pattern;

    for (int i = 0; i < number->count; i++) {
        result += number->digits[i] * number->mults[i];
    }

    return result;
}

bool inc(t_number *number) {
    for (int i = 0; i < number->count; i++) {
        number->digits[i]++;
        number->digits[i] %= 10;
        if (number->digits[i] != 0) {
            return false;
        }
    }

    return true;
}

static int count_unknown(const char *pattern) {
    int count = 0;

    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] == '?') {
            count++;
        }
    }

    return count;
}

static t_number *new_number(int unknown_count) {
    t_number *number = malloc(sizeof(t_number));

    number->pattern = 0;
    number->digits = malloc(sizeof(int) * unknown_count);
    number->mults = malloc(sizeof(int) * unknown_count);
    number->count = unknown_count;

    return number;
}

t_number *parse_pattern(const char *pattern) {
    t_number *number = new_number(count_unknown(pattern));
    int unknown_idx = 0;
    int mult = 1;

    if (pattern[0] == '-') {
        mult = -1;
        pattern++;
    }

    for (int i = mx_strlen(pattern) - 1; i >= 0; i--) {
        if (pattern[i] == '?') {
            number->digits[unknown_idx] = 0;
            number->mults[unknown_idx] = mult;
            unknown_idx++;
        }
        number->pattern += ctod(pattern[i]) * mult;
        mult *= 10;
    }

    return number;
}
