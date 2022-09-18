#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
void mx_printchar(char c);
int mx_strlen(const char *s);
int mx_atoi(const char *str, int *out);
