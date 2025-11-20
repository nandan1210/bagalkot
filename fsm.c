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
                    token[index++] = ch;
                }
                else if (isalpha(ch)) {
                    state = IN_IDENTIFIER;
                    token[index++] = ch;
                }
                else if (ch == '+') {
                    print_token("PLUS", "+");
