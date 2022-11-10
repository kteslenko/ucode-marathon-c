#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int mx_strlen(const char *s);
void mx_printerr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
