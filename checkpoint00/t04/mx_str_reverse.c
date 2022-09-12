static void swap(char *ch1, char *ch2) {
    char temp = *ch1;
    
    *ch1 = *ch2;
    *ch2 = temp;
}

void mx_str_reverse(char *s) {
    char *end = s;

    while (*end != '\0') {
        end++;
    }
    end--;

    while (s != end)
    {
        swap(s, end);
        s++;
        end--;
    }
}
