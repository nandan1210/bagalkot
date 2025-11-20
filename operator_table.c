#include <stdio.h>

struct Operator {
    char symbol[5];
    int precedence;
    char associativity[10];
};

struct Operator opTable[] = {
    {"+", 5, "Left"},
    {"-", 5, "Left"},
    {"*", 4, "Left"},
    {"/", 4, "Left"},
    {"%", 4, "Left"},
    {"<", 6, "Left"},
    {">", 6, "Left"},
    {"<=", 6, "Left"},
    {">=", 6, "Left"},
    {"==", 7, "Left"},
    {"!=", 7, "Left"},
    {"&&", 8, "Left"},
    {"||", 9, "Left"},
    {"=", 10, "Right"}
};

int opCount = sizeof(opTable) / sizeof(opTable[0]);

void displayOperators() {
    printf("\n------ OPERATOR TABLE ------\n");
    printf("Operator\tPrecedence\tAssociativity\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < opCount; i++) {
        printf("%s\t\t%d\t\t%s\n",
               opTable[i].symbol,
               opTable[i].precedence,
               opTable[i].associativity);
    }
}

int main() {
    displayOperators();
    return 0;
}

