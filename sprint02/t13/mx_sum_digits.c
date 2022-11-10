int mx_sum_digits(int num) {
    int sum = 0;

    while (num != 0) {
        int digit = num % 10;

        if (digit < 0) {
            digit *= -1;
        }
        sum += digit;
        num /= 10;
    }

    return sum;
}
