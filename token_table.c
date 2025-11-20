#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Token {
    char lexeme[20];
    char type[20];
};

struct Token table[50];
int count = 0;

void insert(char lex[], char type[]) {
    strcpy(table[count].lexeme, lex);
    strcpy(table[count].type, type);
    count++;
}

int isKeyword(char *word) {
    char *keywords[] = {"int", "float", "if", "else", "while", "return"};
    int size = 6;

    for (int i = 0; i < size; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;

    return 0;
}

void tokenize(char *code) {
    char buf[20];
    int j = 0;

    for (int i = 0; code[i] != '\0'; i++) {
        if (isalpha(code[i])) {
            buf[j++] = code[i];
            while (isalnum(code[++i]))
                buf[j++] = code[i];
            buf[j] = '\0';
            j = 0;
            i--;

            if (isKeyword(buf))
                insert(buf, "KEYWORD");
            else
                insert(buf, "IDENTIFIER");
        }
        else if (isdigit(code[i])) {
            buf[j++] = code[i];
            while (isdigit(code[++i]))
                buf[j++] = code[i];
            buf[j] = '\0';
            j = 0;
            i--;

            insert(buf, "NUMBER");
        }
    }
}

void display() {
    printf("\n----- TOKEN TABLE -----\n");
    printf("Lexeme\tType\n");
    printf("-----------------------\n");

    for (int i = 0; i < count; i++)
        printf("%s\t%s\n", table[i].lexeme, table[i].type);
}

int main() {
    char code[200];

    printf("Enter code: ");
    fgets(code, sizeof(code), stdin);

    tokenize(code);
    display();
    return 0;
}
