#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct s_number {
    long pattern;
    int *digits;
    long *mults;
    int count;
}              t_number;

long ntol(t_number *number); // Converts number to long
bool inc(t_number *number); // Increments the number, returns true if number passed the whole cycle
void del_pattern(t_number *number);
t_number *parse_pattern(const char *pattern);

int ctod(char ch); // Char to digit. ? = 0

bool mx_isdigit(int c);
bool mx_isspace(char c);

void mx_strdel(char **str);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);

bool matches(long number, const char *pattern); // Check if number matches the pattern

int mx_atoi(const char *str);
long lpow(long n, unsigned int pow);
