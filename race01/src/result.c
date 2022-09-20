#include "header.h"

static void print_line(long num1, char op, long num2, long res) {
    mx_printlong(num1);
    mx_printchar(' ');
    mx_printchar(op);
    mx_printchar(' ');
    mx_printlong(num2);
    mx_printstr(" = ");
    mx_printlong(res);
    mx_printchar('\n');
}

void print_res(t_operation *ops, t_number *num1, t_number *num2, const char *pattern) {
    for (int i = 0; i < ops->size; i++) {
        bool finished = false;

        while (!finished) {
            bool finished2 = false;

            while(!finished2) {
                long l1 = ntol(num1);
                long l2 = ntol(num2);
                long res;

                finished2 = inc(num2);

                if (ops->op[i] == '/'
                    && l2 == 0) {
                    continue;
                }

                res = ops->f[i](l1, l2);

                if(matches(res, pattern)) {
                    print_line(l1, ops->op[i], l2, res);
                }
            }
            finished = inc(num1);
        }
    }
}
