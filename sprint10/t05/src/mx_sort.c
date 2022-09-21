#include "agent.h"

void mx_sort(t_agent **arr, int size, bool (*f)(t_agent*, t_agent*)) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < size - 1; i++) {
            if (f(arr[i], arr[i + 1])) {
                t_agent *temp = arr[i];

                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;
            }
        }
    }
}
