#include <unistd.h>
#include <fcntl.h>

static int strlen(const char *s) {
    int len = 0;

    while (*s != '\0') {
        s++;
        len++;
    }

    return len;
}

static void printerr(const char *s) {
    write(2, s, strlen(s));
}

static int print_file(const char* file) {
    int fd = open(file, O_RDONLY);
    ssize_t result;
    char buf;

    if (fd == -1) {
        printerr("error\n");
        return -1;
    }

    while ((result = read(fd, &buf, 1)) > 0) {
        write(1, &buf, 1);
    }
    close(fd);

    if (result == -1) {
        printerr("error\n");
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printerr("usage: ./read_file [file_path]\n");
        return -1;
    }

    return print_file(argv[1]);
}
