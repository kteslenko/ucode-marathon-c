void mx_printchar(char c);

static void left(int first, const int n) {
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

static void right(int first, const int n, int second) {
    if (first <= n - 1
        && first != 1) {
        for (int j = 0; j < second; j++) {
            if (j + 1 == second) {
                mx_printchar('\\');
                break;
            }
            mx_printchar(' ');
        }
    }
}

static void side_first(int third) {
    for (int j = 0; j <= third; j++) {
        if (j == third) {
            mx_printchar('\\');
            break;
        }
        mx_printchar(' ');
    }
}

static void side_second(int third) {
    for (int j = third; j >= 0; j--) {
        if (j - 1 == 0) {
            mx_printchar('|');
            break;
        }
        mx_printchar(' ');
    }
}

static void draw(const int n) {
    int first = n;
    int second = 0;
    int third = 0;

    while (first != 0) {
        left(first, n);
        right(first, n, second);
        second += 2;
        if (first > n / 2) {
            side_first(third);
            third++;
        }
        if (first <= n / 2
            && first != 1) {
            side_second(third);
            third--;
        }
        mx_printchar('\n');
        first--;
    }
}

void mx_pyramid(int n) {
    if (n > 0
        && n % 2 == 0) {
        draw(n);
    }
    else {
        return;
    }
}
