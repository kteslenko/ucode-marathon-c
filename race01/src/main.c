#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
	    mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
	    return -1;
    }

    char *operand1 = mx_strtrim(argv[1]);
    char *operand2 = mx_strtrim(argv[3]);
    char *operation = mx_strtrim(argv[2]);
    char *result = mx_strtrim(argv[4]);
    
    check_args(operand1, operation, operand2, result);

    t_number *number = parse_pattern(operand1);
    t_number *number2 = parse_pattern(operand2);
    t_operation *ops = def_op(*operation);
    print_res(ops, number, number2, result);
}
