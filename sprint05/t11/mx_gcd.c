int mx_gcd(int a, int b) {
    if (b != 0) {
        return mx_gcd(b, a % b);
    }
    if (a < 0) {
        a *= -1;
    }
    return a;
}
