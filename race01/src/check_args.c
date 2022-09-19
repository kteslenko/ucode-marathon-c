#include "../inc/header.h"

void check_args(char *argv[], char *operand1, char *operation, char *operand2, char *result, 
                    int operand1_len, int operation_len, int operand2_len, int result_len) {

    if (operand1_len <= 0) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(-1);
    }
    if (operation_len != 1) {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }
    if (operand2_len <= 0) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[3]);
        mx_printerr("\n");
        exit(-1);
    }
    if (result_len <= 0) {
        mx_printerr("Invalid result: ");
        mx_printerr(argv[4]);
        mx_printerr("\n");
        exit(-1);
    }

    for (int i = 0; i < operand1_len; i++) {
        if (i == 0 && operand1[i] == '-') {
            continue;
        }
        if (operand1[i] != '?' && !mx_isdigit(operand1[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[1]);
            mx_printerr("\n");
            exit(-1);
        }
    }


    if (*operation != '?' && *operation != '+' && *operation != '-' && *operation != '/' && *operation != '*') {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }

    for (int i = 0; i < operand2_len; i++) {
        if (i == 0 && operand2[i] == '-') {
            continue;
        }
        if (operand2[i] != '?' && !mx_isdigit(operand2[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[3]);
            mx_printerr("\n");
            exit(-1);
        }
    }

    for (int i = 0; i < result_len; i++) {
        if (i == 0 && result[i] == '-') {
            continue;
        }
        if (result[i] != '?' && !mx_isdigit(result[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[4]);
            mx_printerr("\n");
            exit(-1);
        }
    }

}
