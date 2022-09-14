int mx_strlen(const char *s);

static void swap(char** a, char** b) {
    char* temp = *a;

    *a = *b;
    *b = temp;
}

int mx_insertion_sort(char **arr, int size) {
    int swaps = 0;

    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0
             && mx_strlen(arr[j - 1]) > mx_strlen(arr[j]); j--) {
            swap(&arr[j - 1], &arr[j]);
            swaps++;
        }
    }

    return swaps;
}
