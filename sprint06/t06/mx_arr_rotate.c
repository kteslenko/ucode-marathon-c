static void rotate_left(int *arr, int size) {
    int temp = arr[0];

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[size - 1] = temp;
}

static void rotate_right(int *arr, int size) {
    int temp = arr[size - 1];

    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp;
}

void mx_arr_rotate(int *arr, int size, int shift) {
    int dir = 1;

    if (shift < 0) {
        dir = -1;
        shift *= -1;
    }

    for (int i = 0; i < shift; i++) {
        if (dir > 0) {
            rotate_right(arr, size);
        }
        else {
            rotate_left(arr, size);
        }
    }
}
