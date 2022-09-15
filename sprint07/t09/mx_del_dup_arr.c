#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);

static int is_duplicate(const int *arr, int idx) {
    for (int i = idx - 1; i >= 0; i--) {
        if (arr[i] == arr[idx]) {
            return 1;
        }
    }

    return 0;
}

static int count_distinct(const int *arr, int size) {
    int count = 0;

    for (int i = 0; i < size; i++)  {
        if (is_duplicate(arr, i) == 0)  {
            count++;
        }
    }

    return count;
}

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    int *dst;
    int dst_idx = 0;

    if (src == NULL
        || src_size == 0) {
        *dst_size = 0;
        return NULL;
    }

    *dst_size = count_distinct(src, src_size);
    dst = malloc(*dst_size * sizeof(int));

    for (int i = 0; i < src_size; i++)  {
        if (is_duplicate(src, i) == 0)  {
            dst[dst_idx] = src[i];
            dst_idx++;
        }
    }

    return dst;
}
