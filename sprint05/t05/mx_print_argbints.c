void mx_printint(int n);
void mx_printchar(char c);
int mx_atoi(const char *str);

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        mx_printint(mx_atoi(argv[i]));
        mx_printchar('\n');
    }
}
