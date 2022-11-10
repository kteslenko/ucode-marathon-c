#include <stdbool.h>

bool mx_isdigit(int c);
int mx_strlen(const char *s);

int mx_atoi(const char *str) {
    if (mx_strlen(str) != 1) {
        return 0;
    }

    if (!mx_isdigit(str[0])) {
        return 0;
    }

    return str[0] - 48;
}
