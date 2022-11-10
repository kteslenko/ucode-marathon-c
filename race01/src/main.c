#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
	    mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
	    return -1;
    }

    char *operand1 = mx_strtrim(argv[1]);
    char *operand2 = mx_strtrim(argv[3]);
    char *operation = mx_strtrim(argv[2]);
    char *result = mx_strtrim(argv[4]);
    bool is_valid = check_args(operand1, operation, operand2, result);
    
    if (is_valid) {
        t_number *number = parse_pattern(operand1);
        t_number *number2 = parse_pattern(operand2);
        t_operation *ops = def_op(*operation);

        print_res(ops, number, number2, result);

        del_number(number);
        del_number(number2);
        del_op(ops);
    }

    mx_strdel(&operand1);
    mx_strdel(&operand2);
    mx_strdel(&operation);
    mx_strdel(&result);

    if (!is_valid) {
        return -1;
    }
}
