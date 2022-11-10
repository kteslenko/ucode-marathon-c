void mx_sort_arr_int(int *arr, int size) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;
        for (int i = 1; i < size; i++) {
            if (arr[i - 1] > arr[i]) {
                int temp = arr[i];

                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                sorted = 0;
            }
        }
    }
}
