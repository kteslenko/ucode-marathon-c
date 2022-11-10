void mx_printchar(char c);

static void printnchar(char c, int n) {
    for (int i = 0; i < n; i++) {
        mx_printchar(c);
    }
}

static void front(int n, int i) {
    char edge = '|';
    char fill = ' ';

    if (i == 0 || i == n / 2 + 1 || i == n * 3 / 2 + 2) {
        edge = '+';
        fill = '-';
    }
    else if (i > 0 && i < n / 2 + 1) {
        edge = '/';
    }

    printnchar(' ', n / 2 + 1 - i);
    mx_printchar(edge);
    printnchar(fill, n * 2);
    mx_printchar(edge);
}

static void side(int n, int i) {
    char edge = '|';
    int space = n / 2;

    if (i == n + 1) {
        edge = '+';
    }
    else if (i < n / 2 + 1) {
        space = i - 1;
    }
    else if (i > n + 1) {
        space = n * 3 / 2 - i + 1;
        edge = '/';
    }

    printnchar(' ', space);
    mx_printchar(edge);
}

void mx_cube(int n) {
    if (n < 2) {
        return;
    }

    for (int i = 0; i < n * 3 / 2 + 3; i++) {
        front(n, i);
        if (i > 0 && i < n * 3 / 2 + 2) {
            side(n, i);
        }
        mx_printchar('\n');
    }
}
