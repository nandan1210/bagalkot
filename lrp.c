#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// ACTION table representation
// s1 = shift 1 -> 11
// r1 = reduce 1 -> -1
// r2 = reduce 2 -> -2
// r3 = reduce 3 -> -3
// acc = 999

// Productions:
// r1 : S → A
// r2 : A → aA
// r3 : A → b

// ACTION[state][terminal]
// terminals: a=0, b=1, $=2

int ACTION[5][3] = {
/* state 0 */ {11, 12, 0},
/* state 1 */ {11, 12, 0},
/* state 2 */ {-3, -3, -3},
/* state 3 */ {-1, -1, 999},
/* state 4 */ {-2, -2, -2}
};

// GOTO table: state × nonterminal A
// Nonterminals: A=0, S=1

int GOTO_TABLE[5][2] = {
/* state 0 */ {3, 0},
/* state 1 */ {4, 0},
/* state 2 */ {0, 0},
/* state 3 */ {0, 0},
/* state 4 */ {0, 0}
};

int stack[MAX];
int top = 0;

// Convert char token to numeric terminal index
int getTerminal(char c) {
    if (c == 'a') return 0;
    if (c == 'b') return 1;
    return 2;  // $
}

int main() {
    char input[100];
    printf("Enter string ending with $ (example: aab$): ");
    scanf("%s", input);

    int ip = 0;       // input pointer
    stack[top] = 0;   // initial state

    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    while (1) {
        int state = stack[top];
        int term = getTerminal(input[ip]);
        int action = ACTION[state][term];

        // Print stack
        printf("[ ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("]\t\t%s\t\t", input + ip);

        // ------------ SHIFT -------------------
        if (action >= 10 && action < 100) {
            int next_state = action % 10;
            printf("shift %d\n", next_state);
            top++;
            stack[top] = next_state;
            ip++;
        }

        // ------------ REDUCE -------------------
        else if (action < 0) {
            int prod = -action;

            if (prod == 1) {       // S → A
                printf("reduce S → A\n");
                // pop 1 symbol (A)
                top--; 
                int st = stack[top];
                top++;
                stack[top] = GOTO_TABLE[st][1]; // goto S
            }
            else if (prod == 2) {  // A → aA
                printf("reduce A → aA\n");
                // pop 2 symbols (A and 'a')
                top -= 2;
                int st = stack[top];
                top++;
                stack[top] = GOTO_TABLE[st][0]; // goto A
            }
            else if (prod == 3) {  // A → b
                printf("reduce A → b\n");
                // pop 1 (b)
                top--;
                int st = stack[top];
                top++;
                stack[top] = GOTO_TABLE[st][0]; // goto A
            }
        }

        // ------------ ACCEPT -------------------
        else if (action == 999) {
            printf("ACCEPTED.\n");
            break;
        }

        // ------------ ERROR ---------------------
        else {
            printf("ERROR.\n");
            break;
        }
    }

    return 0;
}
