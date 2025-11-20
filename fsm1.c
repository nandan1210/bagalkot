#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    printf("Enter string (only 'a' and 'b'): ");
    if (scanf("%999s", s) != 1) return 0;

    int state = 0; // q0 = 0, q1 = 1, q2 = 2

    for (int i = 0; s[i] != '\0'; ++i) {
        char ch = s[i];
        if (ch != 'a' && ch != 'b') {
            printf("Invalid character '%c'. Only 'a' and 'b' allowed.\n", ch);
            return 0;
        }
        switch (state) {
            case 0: // q0
                if (ch == 'a') state = 1;
                else state = 0;
                break;
            case 1: // q1
                if (ch == 'a') state = 1;
                else state = 2;
                break;
            case 2: // q2
                if (ch == 'a') state = 1;
                else state = 0;
                break;
            default:
                state = 0;
        }
    }

    if (state == 2) printf("ACCEPT (string ends with \"ab\")\n");
    else printf("REJECT (string does NOT end with \"ab\")\n");

    return 0;
}
