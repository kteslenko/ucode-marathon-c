#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef long (*t_func)(long, long);

typedef struct s_number {
    long pattern;
    int *digits;
    long *mults;
    int count;
}              t_number;

typedef struct s_operation{
    int size; 
    char *op;
    t_func *f;
}              t_operation;

long ntol(t_number *number);
bool inc(t_number *number);
t_number *new_number(int unknown_count);
void del_number(t_number *number);

t_number *parse_pattern(const char *pattern);

bool matches(long number, const char *pattern);

t_operation *def_op(char c);
void del_op(t_operation *op);

bool check_args(const char *operand1, const char *operation,
                const char *operand2, const char *result);

void print_res(t_operation *ops, t_number *num1, t_number *num2, const char *pattern);

int ctod(char ch);
int wrap_digit(int digit);

bool mx_isdigit(int c);
bool mx_isspace(char c);

void mx_printchar(char c);
void mx_printlong(long n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);

int mx_strlen(const char *s);
void mx_strdel(char **str);
char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strtrim(const char *str);

long add(long a, long b);
long sub(long a, long b);
long mul(long a, long b);
long divis(long a, long b);
