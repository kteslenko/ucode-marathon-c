int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    int shifts = 0;

    for (int i = 1; i < size; i++) {
        char *key = arr[i];
        int j;

        for (j = i - 1; j >= 0
             && mx_strlen(arr[j]) > mx_strlen(key); j--) {
            arr[j + 1] = arr[j];
            shifts++;
        }

        arr[j + 1] = key;
    }

    return shifts;
}
