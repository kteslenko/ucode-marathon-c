void mx_printchar(char c);

static void mx_left(int first, const int n) {
    for (int i = first; i != 1; i--)
        mx_printchar(' ');
    mx_printchar('/');
    if (first == 1) {
        for (int j = 0; j < 2 * n - 3; j++) {
            mx_printchar('_');
            if (j + 1 == 2 * n - 3) {
                mx_printchar('\\');
                mx_printchar('|');
            }
        }
    }
}

static void mx_right(int first, const int n, int second) {
    if (first <= n - 1 && first != 1) {
        for (int j = 0; j < second; j++) {
            if (j + 1 == second) {
                mx_printchar('\\');
                break;
            }
            mx_printchar(' ');
        }
    }
}

static void mx_side_first(int first, const int n, int third) {
        for (int j = 0; j <= third; j++) {
            if (j == third) {
                mx_printchar('\\');
                break;
            }
            mx_printchar(' ');
        }
}

static void mx_side_second(int first, const int n, int third) {
    for (int j = third; j >= 0; j--) {
        if (j - 1 == 0) {
            mx_printchar('|');
            break;
        }
        mx_printchar(' ');
    }
}

static void mx_draw(const int n) {
    int first = n;
    int second = 0;
    int third = 0;

    while (first != 0) {
        mx_left(first, n);
        mx_right(first, n, second);
        second += 2;
        if (first > n / 2) {
            mx_side_first(first, n, third);
            third++;
        }
        if (first <= n / 2 && first != 1) {
            mx_side_second(first, n, third);
            third--;
        }
        mx_printchar('\n');
        first--;
    }
}

void mx_pyramid(int n) {
    if (n > 0 && n % 2 == 0) {
        mx_draw(n);
    }
    else {
        return;
    }
}
