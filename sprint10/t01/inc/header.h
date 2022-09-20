#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int mx_strlen(const char *s);
void mx_printerr(const char *s);
