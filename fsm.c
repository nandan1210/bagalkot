#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    START,
    IN_NUMBER,
    IN_IDENTIFIER,
    DONE
} State;

void print_token(const char* type, const char* value) {
    printf("<%s, %s>\n", type, value);
}

int main() {
    char input[100];
    printf("Enter code: ");
    fgets(input, 100, stdin);

    State state = START;
    char token[100];
    int index = 0;

    for (int i = 0; i <= strlen(input); i++) {
        char ch = input[i];

        switch (state) {

            case START:
                if (isdigit(ch)) {
                    state = IN_NUMBER;
                    index = 0;
                    token[index++] = ch;
                }
                else if (isalpha(ch)) {
                    state = IN_IDENTIFIER;
                    index = 0;
                    token[index++] = ch;
                }
                else if (ch == '+') {
                    print_token("PLUS", "+");
                }
                else if (ch == '-') {
                    print_token("MINUS", "-");
                }
                else if (ch == '*') {
                    print_token("MULTIPLY", "*");
                }
                else if (ch == '/') {
                    print_token("DIVIDE", "/");
                }
                else if (isspace(ch)) {
                    // ignore spaces
                }
                else if (ch == '\0' || ch == '\n') {
                    state = DONE;
                }
                break;

            case IN_NUMBER:
                if (isdigit(ch)) {
                    token[index++] = ch;
                }
                else {
                    token[index] = '\0';
                    print_token("NUMBER", token);
                    index = 0;
                    state = START;
                    i--; // reprocess this character
                }
                break;

            case IN_IDENTIFIER:
                if (isalnum(ch)) {
                    token[index++] = ch;
                }
                else {
                    token[index] = '\0';
                    print_token("IDENTIFIER", token);
                    index = 0;
                    state = START;
                    i--; // reprocess this character
                }
                break;

            case DONE:
                break;

        }
    }

    return 0;
}
