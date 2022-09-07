int mx_mid(int a, int b, int c) {
    if (a > b) {
        if (c > a) {
            return a;
        }
        if (b > c) {
            return b;
        }
    }
    else {
        if (a > c) {
            return a;
        }
        if (c > b) {
            return b;
        }
    }

    return c;
}
