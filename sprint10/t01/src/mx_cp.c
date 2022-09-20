#include "header.h"

void show_error(const char *file) {
    mx_printerr("mx_cp: ");
    mx_printerr(file);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

void copy(int src, int dst) {
    char buf;

    while (read(src, &buf, 1) > 0)
    {
        if (write(dst, &buf, 1) == -1) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    int src;
    int dst;

    if (argc != 3) {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        return -1;
    }
    src = open(argv[1], O_RDONLY);
    if (src == -1) {
        show_error(argv[1]);
        return -1;
    }
    dst = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if (dst == -1) {
        return -1;
    }
    copy(src, dst);
    close(src);
    close(dst);
}
