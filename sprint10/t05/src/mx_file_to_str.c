#include "header.h"

static void strdel(char *str) {
    if (str != NULL) {
        free(str);
    }
}

char *mx_file_to_str(const char *filename) {
    char *str = NULL;
    char *buf = mx_strnew(128);
    int file = open(filename, O_RDONLY);

    if (file != -1) {
        ssize_t result;
        while ((result = read(file, buf, 128)) > 0) {
            char *temp = str;
            
            buf[result] = '\0';
            str = mx_strjoin(str, buf);
            strdel(temp);
        }
        close(file);
    }

    strdel(buf);
    return str;
}
