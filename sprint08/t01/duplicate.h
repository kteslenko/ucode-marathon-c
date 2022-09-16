#pragma once

#include <stdlib.h>

typedef struct s_intarr {
    int *arr;
    int size;
}              t_intarr;

t_intarr *mx_del_dup_sarr(t_intarr *src);
