#include <stdio.h>
#include <string.h>

#define MAX 20

struct Statement {
    char lhs[10];
    char rhs[50];
    int isDead;
};

int main() {
    int n;
    printf("Enter number of statements: ");
    scanf("%d", &n);

    struct Statement s[MAX];

    printf("Enter statements in form: a = b + c\n\n");

    // Input
    for (int i = 0; i < n; i++) {
        printf("S%d: ", i);
        scanf(" %s = %[^\n]", s[i].lhs, s[i].rhs);
        s[i].isDead = 0;
    }

    // -----------------------------
    // Step 1: Common Subexpression Elimination (CSE)
    // -----------------------------
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(s[i].rhs, s[j].rhs) == 0) {
                // s[j] is redundant because expression already computed
                printf("\n[CSE] %s = %s is redundant. Replace with %s.\n",
                       s[j].lhs, s[j].rhs, s[i].lhs);

                sprintf(s[j].rhs, "%s", s[i].lhs); // Replace RHS with reused variable
            }
        }
    }

    // -----------------------------
    // Step 2: Dead Code Elimination (DCE)
    // -----------------------------
    for (int i = 0; i < n; i++) {
        int used = 0;
        for (int j = i + 1; j < n; j++) {
            if (strstr(s[j].rhs, s[i].lhs) != NULL) {
                used = 1;
                break;
            }
        }
        if (!used) {
            s[i].isDead = 1;
        }
    }

    printf("\n========= Optimized Code =========\n");

    for (int i = 0; i < n; i++) {
        if (!s[i].isDead) {
            printf("%s = %s\n", s[i].lhs, s[i].rhs);
        }
        else {
            printf("[DCE] Removed dead statement: %s = %s\n", s[i].lhs, s[i].rhs);
        }
    }

    return 0;
}
