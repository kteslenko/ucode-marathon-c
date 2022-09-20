#include "../inc/header.h"

static bool check_operation(const char* operation) {
    return mx_strlen(operation) == 1
           && (operation[0] == '?'
           || operation[0] == '+'
           || operation[0] == '-'
           || operation[0] == '*'
           || operation[0] == '/');
}

static bool check_pattern(const char* pattern) {
    int len = mx_strlen(pattern);

    if (len == 0) {
        return false;
    }
    if (pattern[0] == '-') {
        if (len == 1) {
            return false;
        }
        len--;
        pattern++;
    }
    for (int i = 0; i < len; i++) {
        if (pattern[i] != '?'
            && !mx_isdigit(pattern[i])) {
            return false;
        }
    }

    return true;
}

static void show_error(const char *error, const char *value) {
    mx_printerr(error);
    mx_printerr(": ");
    mx_printerr(value);
    mx_printerr("\n");
    exit(-1);
}

void check_args(const char *operand1, const char *operation,
                const char *operand2, const char *result) {
    if (!check_operation(operation)) {
        show_error("Invalid operation", operation);
    }
    if (!check_pattern(operand1)) {
        show_error("Invalid operand", operand1);
    }
    if (!check_pattern(operand2)) {
        show_error("Invalid operand", operand2);
    }
    if (!check_pattern(result)) {
        show_error("Invalid result", result);
    }
}
