#include "duplicate.h"

static int is_duplicate(const int *arr, int idx) {
    for (int i = idx - 1; i >= 0; i--) {
        if (arr[i] == arr[idx]) {
            return 1;
        }
    }

    return 0;
}

static int count_distinct(t_intarr *src) {
    int count = 0;

    for (int i = 0; i < src->size; i++)  {
        if (is_duplicate(src->arr, i) == 0)  {
            count++;
        }
    }

    return count;
}

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    t_intarr *dst;
    int dst_idx = 0;

    if (src == NULL
        || src->arr == NULL
        || src->size == 0) {
        return NULL;
    }

    dst = malloc(sizeof(t_intarr));
    dst->size = count_distinct(src);
    dst->arr = malloc(dst->size * sizeof(int));

    for (int i = 0; i < src->size; i++)  {
        if (is_duplicate(src->arr, i) == 0)  {
            dst->arr[dst_idx] = src->arr[i];
            dst_idx++;
        }
    }
    return dst;
}
