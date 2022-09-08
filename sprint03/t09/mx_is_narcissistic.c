#include <stdbool.h>

double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num) {
    int count = 0;
    int sum = 0;

    for (int i = num; i != 0; i /= 10) {
        count++;
    }

    for (int i = num; i != 0; i /= 10) {
        int digit = i % 10;

        if (digit < 0) {
            digit *= -1;
        }

        sum += mx_pow(digit, count);
    }

    return sum == num;
}
