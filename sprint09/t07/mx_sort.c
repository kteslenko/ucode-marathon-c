#include <stdbool.h>

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < size - 1; i++) {
            if (f(arr[i], arr[i + 1])) {
                int temp = arr[i];

                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;
            }
        }
    }
}
