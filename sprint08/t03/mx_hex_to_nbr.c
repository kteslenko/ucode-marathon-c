#include "hex_to_nbr.h"

static int hex_digit_to_dec(char digit) {
    if (mx_isdigit(digit)) {
        return digit - 48;
    }
    if (digit >= 97 && digit <= 102) {
        digit -= 32;
    }
    if (digit >= 65 && digit <= 70) {
        return digit - 55;
    }
    return -1;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    int nbr = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
        int digit = hex_digit_to_dec(hex[i]);

        if (digit == -1) {
            return 0;
        }

        nbr *= 16;
        nbr += digit;
    }

    return nbr;
}
