#include <time.h>

double mx_timer(void (*f)()) {
    clock_t t = clock();
    f();
    t = clock() - t;
    return (double)t/CLOCKS_PER_SEC;
}
