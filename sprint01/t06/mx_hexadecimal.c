void mx_printchar(char c);

void mx_hexadecimal(void) {
    for (int i = 48; i < 71; i++) {
        if (i == 58) {
            i = 65;
        }
        
        mx_printchar((char)i);
    }

    mx_printchar('\n');
}
