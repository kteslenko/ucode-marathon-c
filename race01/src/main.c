#include <stdio.h>

#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
	    mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]");
	    return 1;
    }

    char *operand1 = mx_strtrim(argv[1]);
    char *operand2 = mx_strtrim(argv[3]);
    char *operator = mx_strtrim(argv[2]);
    char *result = mx_strtrim(argv[4]);
    
    int operand1_len = mx_strlen(operand1);
    int operand2_len = mx_strlen(operand2);
    int operation_len = mx_strlen(operation);
    int result_len = mx_strlen(result);

    check_args(argv, operand1, operation, operand2, result, operand1_len, 
		    operation_len, operand2_len, result_len);

    t_number *number = parse_pattern(operand1);
    t_number *number2 = parse_pattern(operand2);
    t_operation *ops = def_op(*operator);
    print_res(ops, number, number2, result);
}
