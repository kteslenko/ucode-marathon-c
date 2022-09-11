#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c) {
    write(1, &c, 1);
}

static void mx_draw(const int n) {
    int first = n;
    int second = 2;
    int third = 0;
// LEFT
    while (first != 0) {
        for (int i = first; i != 1; i--)
            mx_printchar(' ');
        mx_printchar('/');
// LEFT
        
// RIGHT
        if (first <= n - 1 && first != 1) {
            for (int j = 0; j < second; j++) {
                if (j + 1 == second) {
                    mx_printchar('\\');
                    break;
                }
                mx_printchar(' ');
            }
            second += 2;
        }
// RIGHT

// SIDE "\"
        if (first > n / 2) {
            for (int j = 0; j <= third; j++) {
                if (j == third) {
                    mx_printchar('\\');
                    break;
                }
                mx_printchar(' ');
            }
            third++;
        }
// SIDE "\"

// SIDE "|"
        if (first <= n / 2 && first != 1) {
            for (int j = third; j >= 0; j--) {
                if (j - 1 == 0) {
                    mx_printchar('|');
                    break;
                }
                mx_printchar(' ');
            }
            third--;
        }
// SIDE "|"
        
// LAST LINE
        if (first == 1) {
            for (int j = 0; j < 2 * n - 3; j++) {
                mx_printchar('_');
                if (j + 1 == 2 * n - 3) {
                    mx_printchar('\\');
                    mx_printchar('|');
                }
            }
        }
// LAST LINE
        mx_printchar('\n');
        first--;
    }
}

void mx_pyramid(int n) {
    if (n > 0 && n % 2 == 0) {
        mx_draw(n);
    }
    else {
        return;
    }
}

int main() {
    int size;
    printf("Enter size of pyramid(odd numbers and greater than 0: ");
    scanf("%d", &size);
    mx_pyramid(size);
    return 0;
}

