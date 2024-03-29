#include "../inc/calculator.h"

static t_operation *create_operation(char op, int (*f)(int, int)) {
    t_operation *operation = malloc(sizeof(t_operation));
    operation->op = op;
    operation->f = f;
    return operation;
}

static t_operation **create_operations() {
    t_operation **operations = malloc(sizeof(t_operation*) * 6);
    operations[0] = create_operation('-', mx_sub);
    operations[1] = create_operation('+', mx_add);
    operations[2] = create_operation('*', mx_mul);
    operations[3] = create_operation('/', mx_div);
    operations[4] = create_operation('%', mx_mod);
    operations[5] = NULL;
    return operations;
}

static int parse_operator(char *op_str, enum e_operation *operation) {
    static const char operators[] = {'-', '+', '*', '/', '%'};
    char op;
    
    if (op_str == NULL
        || mx_strlen(op_str) != 1)
        return -1;

    op = op_str[0];

    for (int i = 0; i < 5; i++) {
        if (operators[i] == op) {
            *operation = (enum e_operation)i;
            return 0;
        }
    }

    return -1;
}

static t_operation *get_operation(char *op_str) {
    t_operation **operations;
    enum e_operation operation;

    if (parse_operator(op_str, &operation) != 0)
        return NULL;

    operations = create_operations();
    return operations[(int)operation];
}

static void print_usage() {
    mx_printerr("usage: ./calc [operand1] [operation] [operand2]\n");
    exit(0);
}

static void handle_error(enum e_error error) {
    switch (error) {
        case INCORRECT_OPERAND:
            mx_printerr("error: invalid number\n");
            break;
        case INCORRECT_OPERATION:
            mx_printerr("error: invalid operation\n");
            break;
        case DIV_BY_ZERO:
            mx_printerr("error: division by zero\n");
            break;
        default:
            break;
    }
    exit(0);
}

int main(int argc, char *argv[]) {
    t_operation *operation;
    int operands[2];

    if (argc != 4)
        print_usage();
    
    if (mx_atoi(argv[1], &operands[0]) != 0
        || mx_atoi(argv[3], &operands[1]) != 0)
        handle_error(INCORRECT_OPERAND);

    operation = get_operation(argv[2]);
    if (operation == NULL)
        handle_error(INCORRECT_OPERATION);

    if (operation->op == '/'
        && operands[1] == 0)
        handle_error(DIV_BY_ZERO);

    mx_printint(operation->f(operands[0], operands[1]));
    mx_printstr("\n");
}
