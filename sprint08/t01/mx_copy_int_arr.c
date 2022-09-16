#include "duplicate.h"

int *mx_copy_int_arr(const int *src, int size) {
    int *arr;

    if (src == NULL
        || size == 0) {
        return NULL;
    }

    arr = malloc(size * sizeof(int));

    if (arr == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = src[i];
    }

    return arr;
}
