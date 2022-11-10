int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcat(char *s1, const char *s2);

char *mx_strjoin(char const *s1, char const *s2) {
    char *str;

    if (s1 == 0 && s2 == 0) {
        return 0;
    }
    if (s1 == 0 && s2 != 0) {
        return mx_strdup(s2);
    }
    if (s1 != 0 && s2 == 0) {
        return mx_strdup(s1);
    }

    str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcat(str, s1);
    mx_strcat(str, s2);
    return str;
}
