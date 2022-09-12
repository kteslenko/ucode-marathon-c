void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

static void ssort(char **arr, int size) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;
        for (int i = 1; i < size; i++) {
            if (mx_strcmp(arr[i - 1], arr[i]) > 0) {
                char* temp = arr[i];

                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                sorted = 0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ssort(argv + 1, argc - 1);
    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printstr("\n");
    }
}
