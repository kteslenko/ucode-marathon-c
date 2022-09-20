#include "../inc/header.h"

t_operation *def_op(char c){
    int idx = 0;
    static const char ops[] = {'+', '-', '*', '/'};
    static const t_func funcs[] = {add, sub, mul, divis};
    t_operation *oper = malloc(sizeof(t_operation));

    oper->size = 0;
    oper->op = malloc(sizeof(char) * 4);
    oper->f = malloc(sizeof(t_func) * 4);

    for (int i = 0; i < 4; i++) {
        if (c == ops[i] || c == '?') {
            oper->op[idx] = ops[i];
            oper->f[idx] = funcs[i];
            oper->size++;
            idx++;
        }
    }

    return oper;
}

void del_op(t_operation *op) {
    if (op == NULL)
        return;
    if (op->op != NULL)
        free(op->op);
    if (op->f != NULL)
        free(op->f);
    free(op);
}
