#include "header.h"

static void show_error(const char *file) {
    mx_printerr("mx_cat: ");
    mx_printerr(file);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

static void copy(int src, int dst) {
    char buf;

    while (read(src, &buf, 1) > 0)
    {
        if (write(dst, &buf, 1) == -1) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        copy(0, 1);
    }
    else if (argc == 2) {
        int src = open(argv[1], O_RDONLY);
        if (src == -1) {
            show_error(argv[1]);
            return -1;
        }
        copy(src, 1);
        close(src);
    }
}
