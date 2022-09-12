void mx_printint(int n);
void mx_printstr(const char *s);

int main(int argc, char *argv[])  {
    mx_printstr(argv[0]);
    mx_printstr("\n");
    mx_printint(argc);
    mx_printstr("\n");
}
