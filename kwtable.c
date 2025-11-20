#include <stdio.h>
#include <string.h>

#define MAX_KEYWORDS 10

// Enum for token types
typedef enum {
    KW_INT, KW_FLOAT, KW_IF, KW_ELSE, KW_WHILE, KW_FOR, KW_RETURN
} TokenType;

// Struct for each keyword entry
typedef struct {
    char lexeme[20];     // actual keyword text
    TokenType token;     // internal token code
    char category[20];   // optional: keyword category
} Keyword;

// Keyword table (array of structs)
Keyword keywordTable[MAX_KEYWORDS] = {
    {"int",    KW_INT,    "datatype"},
    {"float",  KW_FLOAT,  "datatype"},
    {"if",     KW_IF,     "conditional"},
    {"else",   KW_ELSE,   "conditional"},
    {"while",  KW_WHILE,  "loop"},
    {"for",    KW_FOR,    "loop"},
    {"return", KW_RETURN, "jump"}
};

int keywordCount = 7;

// Function to search a keyword in the table
int searchKeyword(char *word) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(keywordTable[i].lexeme, word) == 0) {
            return i;  // return index of keyword
        }
    }
    return -1; // not a keyword
}

int main() {
    char word[30];

    printf("Enter a word: ");
    scanf("%s", word);

    int idx = searchKeyword(word);

    if (idx != -1) {
        printf("\"%s\" is a KEYWORD\n", word);
        printf("Token Type: %d\n", keywordTable[idx].token);
        printf("Category: %s\n", keywordTable[idx].category);
    } else {
        printf("\"%s\" is an IDENTIFIER\n", word);
    }

    return 0;
}
