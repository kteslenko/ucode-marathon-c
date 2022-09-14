int mx_strcmp(const char *s1, const char *s2);

int mx_bubble_sort(char **arr, int size) {
    int sorted = 0;
    int swaps = 0;

    while (!sorted) {
        sorted = 1;
        for (int i = 1; i < size; i++) {
            if (mx_strcmp(arr[i - 1], arr[i]) > 0) {
                char* temp = arr[i];

                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                sorted = 0;
                swaps++;
            }
        }
    }

    return swaps;
}
