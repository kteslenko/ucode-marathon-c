void mx_foreach(const int *arr, int size, void (*f)(int)) {
    if (arr == 0
        || f == 0) {
        return;
    }

    for (int i = 0; i < size; i++) {
        f(arr[i]);
    }
} 
