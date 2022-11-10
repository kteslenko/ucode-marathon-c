#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

void mx_printint(int n);
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
bool mx_isspace(char c);
int mx_strlen(const char *s);
char *mx_strchr(const char *s, int c);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strstr(const char *s1, const char *s2);
int mx_strcmp(const char *s1, const char *s2);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_file_to_str(const char *filename);
char *mx_strndup(const char *str, int n);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
char *mx_strncpy(char *dst, const char *src, int len);
