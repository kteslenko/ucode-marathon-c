#include <stdio.h>

#include "../inc/header.h"

int main(void) {
    t_number *number = parse_pattern("?6?");
    t_number *number2 = parse_pattern("???");
    t_operation *ops = def_op('?');
    print_res(ops, number, number2, "6?");
}
