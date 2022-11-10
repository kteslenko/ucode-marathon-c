#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "list.h"

typedef struct s_song {
    char *name;
    char *artist;
}              t_song;

int mx_atoi(const char *str, int *out);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strchr(const char *s, int c);
void mx_printstr(const char *s);
void mx_printint(int n);
void mx_printerr(const char *s);
void mx_printchar(char c);
char *mx_file_to_str(const char *filename);
char *mx_strndup(const char *str, int n);
bool mx_isspace(char c);
bool mx_isdigit(int c);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);
char *mx_strncpy(char *dst, const char *src, int len);
