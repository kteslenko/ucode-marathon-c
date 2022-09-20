#include "../inc/header.h"

long ntol(t_number *number) {
    long result = number->pattern;

    for (int i = 0; i < number->count; i++) {
        result += number->digits[i] * number->mults[i];
    }

    return result;
}

static bool is_negative(t_number *number) {
    return number->pattern < 0
           || (number->count > 0
           && number->mults[0] < 0);
}

static bool is_negative_zero(t_number *number) {
    if (number->pattern != 0
        || number->count == 0
        || number->mults[0] > 0) {
        return false;
    }

    for (int i = 0; i < number->count; i++) {
        if (number->digits[i] != 0) {
            return false;
        }
    }
    
    return true;
}

bool inc(t_number *number) {
    int inc = is_negative(number) ? -1 : 1;

    for (int i = 0; i < number->count; i++) {
        number->digits[i] += inc;
        number->digits[i] = wrap_digit(number->digits[i]);
        if (is_negative_zero(number)) {
            i = -1;
            continue;
        }
        if ((inc > 0 && number->digits[i] != 0)
            || (inc < 0 && number->digits[i] != 9)) {
            return false;
        }
    }

    return true;
}

t_number *new_number(int unknown_count) {
    t_number *number = malloc(sizeof(t_number));

    number->pattern = 0;
    number->digits = malloc(sizeof(int) * unknown_count);
    number->mults = malloc(sizeof(long) * unknown_count);
    number->count = unknown_count;

    return number;
}

void del_number(t_number *number) {
    if (number == NULL)
        return;
    if (number->digits != NULL)
        free(number->digits);
    if (number->mults != NULL)
        free(number->mults);
    free(number);
}
