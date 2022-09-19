#include <stdio.h>

#include "../inc/header.h"

int main(void) {
    t_number *number = parse_pattern("?6?");
    bool finished = false;

    while (!finished) {
        printf("%d\n", ntoi(number));
        finished = inc(number);
    }
}
