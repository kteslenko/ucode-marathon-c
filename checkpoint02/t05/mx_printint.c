#include <unistd.h>

void mx_printint(int n) {
    int pow = 1;

    if (n < 0) {
        write(1, "-", 1);
        pow *= -1;
    }

    for (int i = n; i >= 10
         || i <= -10; i /= 10) {
        pow *= 10;
    }
    
    while (pow != 0) {
        int c = 48 + n / pow;

        write(1, &c, 1);
        n %= pow;
        pow /= 10;
    }
}
