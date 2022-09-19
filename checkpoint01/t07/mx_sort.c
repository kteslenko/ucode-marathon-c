#include <stdbool.h>

static void swap(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    bool sorted = false;

    if (arr == 0
        || f == 0) {
        return;
    }

    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++) {
            if (f(arr[i], arr[i + 1])) {
                swap(&arr[i], &arr[i + 1]);
                sorted = false;
            }
        }
    }
}
