void mx_printchar(char c);

void mx_printint(int n) {
    for (int i = 31; i >= 0; i--) {
        int bit = ((n & (1 << i)) >> i) & 1;
        mx_printchar(48 + bit);
    }
}
