void mx_strdel(char **str);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);

char *mx_concat_words(char **words) {
    char *str;

    if (words == 0
        || words[0] == 0) {
        return 0;
    }

    str = mx_strdup(words[0]);

    for (int i = 1; words[i] != 0; i++) {
        char *temp;
        char *word = mx_strjoin(" ", words[i]);

        temp = str;
        str = mx_strjoin(str, word);
        mx_strdel(&temp);
        mx_strdel(&word);
    }

    return str;
}
