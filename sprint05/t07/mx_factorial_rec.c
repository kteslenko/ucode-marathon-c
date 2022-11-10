int mx_factorial_rec(int n) {
    if (n < 0) {
        return 0;
    }
    if (n < 2) {
        return 1;
    }

    int prev = mx_factorial_rec(n - 1);

    if (prev == 0
        || 2147483647 / prev < n) {
        return 0;
    }

    return n * prev;
}
