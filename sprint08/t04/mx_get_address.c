#include "get_address.h"

char *mx_get_address(void *p) {
    char *addr = mx_nbr_to_hex((unsigned long)p);
    char *result = mx_strnew(mx_strlen(addr) + 2);
    mx_strcpy(result, "0x");
    mx_strcpy(result + 2, addr);
    free(addr);
    return result;
}
