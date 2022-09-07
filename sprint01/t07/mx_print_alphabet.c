void mx_printchar(char c);

void mx_print_alphabet(void) {
    for (int i = 65; i < 91; i++) {
        int ch = i;

        if (ch % 2 == 0) {
            ch += 32;
        }

        mx_printchar((char)ch);
    }

    mx_printchar('\n');
}
