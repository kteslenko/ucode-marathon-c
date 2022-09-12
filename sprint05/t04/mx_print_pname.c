char *mx_strchr(const char *s, int c);
void mx_printstr(const char *s);

int main(int argc, char *argv[]) {
    char *name = argv[0];
    char *temp = name;

    if (argc < 1) {
        return 0;
    }

    while ((temp = mx_strchr(temp, '/')) != 0) {
        name = temp + 1;
        temp++;
    }

    mx_printstr(name);
    mx_printstr("\n");
}
