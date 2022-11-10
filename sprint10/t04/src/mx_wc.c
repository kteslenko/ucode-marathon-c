#include "header.h"

static void show_error(const char *file) {
    mx_printerr("mx_wc: ");
    mx_printerr(file);
    mx_printerr(": open: ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

static t_wc wc(int src) {
    t_wc result = {0, 0, 0};
    char buf;
    bool space = false;

    while (read(src, &buf, 1) > 0) {
        if (buf == '\n') {
            result.lines++;
        }
        if (mx_isspace(buf)) {
            if (!space) {
                result.words++;
            }
            space = true;
        } else {
            space = false;
        }
        result.chars++;
    }

    return result;
}

static void print_wc(const t_wc *wc, const char *filename) {
    mx_printchar('\t');
    mx_printint(wc->lines);
    mx_printchar('\t');
    mx_printint(wc->words);
    mx_printchar('\t');
    mx_printint(wc->chars);
    if (filename != NULL) {
        mx_printchar(' ');
        mx_printstr(filename);
    }
    mx_printchar('\n');
}

static void add_wc(t_wc *out, t_wc *wc) {
    out->lines += wc->lines;
    out->words += wc->words;
    out->chars += wc->chars;
}

int main(int argc, char *argv[]) {
    t_wc total = {0, 0, 0};

    if (argc == 1) {
        t_wc res = wc(0);
        print_wc(&res, NULL);
    }
    for (int i = 1; i < argc; i++) {
        t_wc res;

        if (mx_strcmp(argv[i], "-") == 0) {
            res = wc(0);
        }
        else {
            int src = open(argv[i], O_RDONLY);
            if (src == -1) {
                show_error(argv[i]);
                continue;
            }
            res = wc(src);
            close(src);
        }

        add_wc(&total, &res);
        print_wc(&res, argv[i]);
    }
    if (argc > 2) {
        print_wc(&total, "total");
    }
}
