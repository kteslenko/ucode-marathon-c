int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);

static void swap(char **a, char **b) {
    char* temp = *a;

    *a = *b;
    *b = temp;
}

static int compare(char *a, char *b) {
    int cmp = mx_strlen(a) - mx_strlen(b);

    if (cmp == 0) {
        cmp = mx_strcmp(a, b);
    }

    return cmp;
}

int mx_selection_sort(char **arr, int size) {
    int swaps = 0;

    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < size; j++) {
            if (compare(arr[min_idx], arr[j]) > 0) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
            swaps++;
        }
    }

    return swaps;
}
