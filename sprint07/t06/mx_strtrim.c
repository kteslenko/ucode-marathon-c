#include <stdbool.h>

bool mx_isspace(char c);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);

char *mx_strtrim(const char *str) {
    int len;
    char *new_str;

    if (str == 0) {
        return 0;
    }
    while (mx_isspace(*str)) {
        str++;
    }
    len = mx_strlen(str);
    while (len > 0 && mx_isspace(str[len - 1]))
    {
        len--;
    }
    new_str = mx_strnew(len);
    return mx_strncpy(new_str, str, len);
}
