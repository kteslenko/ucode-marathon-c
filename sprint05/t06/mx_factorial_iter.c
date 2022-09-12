int mx_factorial_iter(int n) {
    int result = 1;

    if (n < 0) {
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        if (2147483647 / result < i) {
            return 0;
        }

        result *= i;
    }

    return result;
}
