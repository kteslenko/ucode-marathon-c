static int isspace(char c) {
    return (c >= 9
            && c <= 13)
            || c == 32;
}

static int isdigit(char c) {
    return c >= 48 && c <= 57;
}

int mx_atoi(const char *str) {
    int result = 0;
    int mult = 1;

    while (isspace(*str)
           || *str == '+') {
        str++;
    }

    if (*str == '-') {
        mult = -1;
        str++;
    }

    while (isdigit(*str)) {
        result *= 10;
        result += (*str - 48) * mult;
        str++;
    }

    return result;
}
