void mx_printint(int n);
void mx_printchar(char c);
int mx_atoi(const char *str);

static void print_table(int start, int end) {
    for (int i = start; i <= end; i++) {
        for (int j = start; j <= end; j++) {
            mx_printint(i * j);
            if (j != end) {
                mx_printchar('\t');
            }
        }
        mx_printchar('\n');
    }
}

int main(int argc, char *argv[]) {
    int start;
    int end;

    if (argc != 3) {
        return 0;
    }

    start = mx_atoi(argv[1]);
    end = mx_atoi(argv[2]);
    if (start < 1
        || end < 1) {
        return 0;
    }
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    print_table(start, end);
}
