#include "get_address.h"

#include <stdlib.h>

static void strdel(char **str) {
    if (str == NULL) {
        return;
    }
    if (*str == NULL) {
        return;
    }
    free(*str);
    *str = NULL;
}

char *mx_get_address(void *p) {
    char *addr = mx_nbr_to_hex((unsigned long)p);
    char *result = mx_strnew(mx_strlen(addr) + 2);
    mx_strcpy(result, "0x");
    mx_strcpy(result + 2, addr);
    strdel(&addr);
    return result;
}
