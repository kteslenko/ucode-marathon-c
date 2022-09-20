#include "header.h"

static void print_file(const char* file) {
    int fd = open(file, O_RDONLY);
    ssize_t result;
    char buf;

    if (fd == -1) {
        mx_printerr("error\n");
        exit(-1);
    }

    while ((result = read(fd, &buf, 1)) > 0) {
        write(1, &buf, 1);
    }

    close(fd);

    if (result == -1) {
        mx_printerr("error\n");
        exit(-1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./read_file [file_path]\n");
        return -1;
    }

    print_file(argv[1]);
}
