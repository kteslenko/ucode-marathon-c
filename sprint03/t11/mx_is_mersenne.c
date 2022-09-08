#include <stdbool.h>

bool mx_is_prime(int num);
double mx_pow(double n, unsigned int pow);

bool mx_is_mersenne(int n) {
    double pow = 0;

    if (!mx_is_prime(n)) {
        return false;
    }

    for (int i = 0; pow < n; i++) {
        pow = mx_pow(2, i);
    }

    return pow - n == 1;
}
