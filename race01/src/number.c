#include "../inc/header.h"

long ntol(t_number *number) {
    long result = number->pattern;

    for (int i = 0; i < number->count; i++) {
        result += number->digits[i] * number->mults[i];
    }

    return result;
}

static bool is_negative_zero(t_number *number) {
    return number->pattern == 0
           && number->count > 0
           && number->mults[0] < 0;
}

bool inc(t_number *number) {
    for (int i = 0; i < number->count; i++) {
        number->digits[i]++;
        number->digits[i] %= 10;
        if (number->digits[i] != 0) {
            return false;
        }
    }

    if (is_negative_zero(number)) {
        number->digits[0]++;
    }

    return true;
}

static int count_unknown(const char *pattern) {
    int count = 0;

    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] == '?') {
            count++;
        }
    }

    return count;
}

static t_number *new_number(int unknown_count) {
    t_number *number = malloc(sizeof(t_number));

    number->pattern = 0;
    number->digits = malloc(sizeof(int) * unknown_count);
    number->mults = malloc(sizeof(long) * unknown_count);
    number->count = unknown_count;

    return number;
}

void del_number(t_number *number) {
    if (number == NULL)
        return;
    if (number->digits != NULL)
        free(number->digits);
    if (number->mults != NULL)
        free(number->mults);
    free(number);
}

t_number *parse_pattern(const char *pattern) {
    t_number *number = new_number(count_unknown(pattern));
    int unknown_idx = 0;
    long mult = 1;

    if (pattern[0] == '-') {
        mult = -1;
        pattern++;
    }

    for (int i = mx_strlen(pattern) - 1; i >= 0; i--) {
        if (pattern[i] == '?') {
            number->digits[unknown_idx] = 0;
            number->mults[unknown_idx] = mult;
            unknown_idx++;
        }
        number->pattern += ctod(pattern[i]) * mult;
        mult *= 10;
    }

    if (is_negative_zero(number)) {
        number->digits[0]++;
    }

    return number;
}

t_operation *def_op(char c){
    t_operation *oper = malloc(sizeof(t_operation));
    if (c == '?'){
        char *arr = malloc(32);
        arr[0] = '+';
        arr[1] = '-';
        arr[2] = '*';
        arr[3] = '/';
        oper->op = arr;
        long (**func)(long a, long b) = malloc(sizeof(void*) * 4);
        func[0] = add;
        func[1] = sub;
        func[2] = mul;
        func[3] = divis;
        oper->f = func;
        oper->size = 4;
    }
    else {
        char *arr = malloc(8);
        arr[0] = c;
        oper->op = arr;
        long (**func)(long a, long b) = malloc(sizeof(void*));
        if (c == '+') func[0] = add;
        if (c == '-') func[0] = sub;
        if (c == '*') func[0] = mul;
        if (c == '/') func[0] = divis;
        oper->f = func;
        oper->size = 1;
    }
    return oper;
}
void print_res(t_operation *ops, t_number *num1, t_number *num2, const char *pattern){
    for (int i = 0; i < ops->size; i++){
        bool finished = false;
        while (!finished){
            bool finished2 = false;
            while(!finished2){
                if((ops->op[i] != '/' || ntol(num2) != 0) && matches(ops->f[i](ntol(num1), ntol(num2)), pattern)){
                    printf("%li %c %li = %li\n", ntol(num1), ops->op[i], ntol(num2), ops->f[i](ntol(num1), ntol(num2)));
                }
                finished2 = inc(num2);
            }
            finished = inc(num1);
        }
    }
}

