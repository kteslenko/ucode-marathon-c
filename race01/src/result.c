#include "../inc/header.h"

void print_res(t_operation *ops, t_number *num1, t_number *num2, const char *pattern){
    for (int i = 0; i < ops->size; i++){
        bool finished = false;
        while (!finished){
            bool finished2 = false;
            while(!finished2){
                if((ops->op[i] != '/' || ntol(num2) != 0) && matches(ops->f[i](ntol(num1), ntol(num2)), pattern)){
                    mx_printlong(ntol(num1));
                    mx_printchar(' ');
                    mx_printchar(ops->op[i]);
                    mx_printchar(' ');
                    mx_printlong(ntol(num2));
                    mx_printstr(" = ");
                    mx_printlong(ops->f[i](ntol(num1), ntol(num2)));
                    mx_printchar('\n');
                }
                finished2 = inc(num2);
            }
            finished = inc(num1);
        }
    }
}
