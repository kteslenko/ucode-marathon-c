#include <stdbool.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);

int mx_atoi(const char *str) {
    int mult = 1;
    int result = 0;

    while (mx_isspace(*str)
           || *str == '+') {
        str++;
    }

    if (*str == '-') {
        mult = -1;
        str++;
    }

    for (int i = 0; mx_isdigit(str[i]); i++) {
        result *= 10;
        result += (str[i] - 48) * mult;
    }

    return result;
}
