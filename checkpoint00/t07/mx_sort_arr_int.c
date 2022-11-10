void mx_sort_arr_int(int *arr, int size) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];

                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;
            }
        }
    }
}
