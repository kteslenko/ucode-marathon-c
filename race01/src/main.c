#include <stdio.h>

#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 5) return 1;
    char *operand1 = mx_strtrim(argv[1]);
    char *operand2 = mx_strtrim(argv[3]);
    char *operator = mx_strtrim(argv[2]);
    char *result = mx_strtrim(argv[4]);
    t_number *number = parse_pattern(operand1);
    t_number *number2 = parse_pattern(operand2);
    t_operation *ops = def_op(*operator);
    print_res(ops, number, number2, result);
}
