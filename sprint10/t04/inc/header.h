#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

typedef struct s_wc {
    int lines;
    int words;
    int chars;
} t_wc;

void mx_printint(int n);
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
bool mx_isspace(char c);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcat(char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_file_to_str(const char *filename);
