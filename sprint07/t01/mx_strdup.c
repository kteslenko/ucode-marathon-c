int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str) {
    char *new_str = mx_strnew(mx_strlen(str));

    if (new_str == 0) {
        return 0;
    }

    return mx_strcpy(new_str, str);
}
