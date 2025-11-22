#include <stdio.h>
#include <string.h>

#define MAX 100

// structure to hold each TAC instruction
struct Instr {
    char op[10];
    char arg1[20];
    char arg2[20];
    char res[20];
};

int main() {
    int n;
    printf("Enter number of TAC instructions: ");
    scanf("%d", &n);

    struct Instr code[MAX];

    printf("Enter TAC in form: res op arg1 arg2\n");
    printf("Example: t1 = a + b   →   t1 + a b\n\n");

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %s", code[i].res, code[i].op, code[i].arg1, code[i].arg2);
    }

    printf("\n===== Optimized Code (Peephole Applied) =====\n");

    for (int i = 0; i < n; i++) {
        int remove = 0;

        // -------- Peephole Rules Start --------

        // Eliminate x = x
        if (strcmp(code[i].op, "=") == 0 && strcmp(code[i].res, code[i].arg1) == 0)
            remove = 1;

        // Algebraic simplifications
        if (strcmp(code[i].op, "+") == 0 && strcmp(code[i].arg2, "0") == 0)
            remove = 1;

        if (strcmp(code[i].op, "-") == 0 && strcmp(code[i].arg2, "0") == 0)
            remove = 1;

        if (strcmp(code[i].op, "*") == 0 && strcmp(code[i].arg2, "1") == 0)
            remove = 1;

        if (strcmp(code[i].op, "/") == 0 && strcmp(code[i].arg2, "1") == 0)
            remove = 1;

        // Duplicate instruction elimination
        if (i > 0 &&
            strcmp(code[i].op, code[i - 1].op) == 0 &&
            strcmp(code[i].arg1, code[i - 1].arg1) == 0 &&
            strcmp(code[i].arg2, code[i - 1].arg2) == 0)
        {
            remove = 1;
        }

        // -------- Peephole Rules End --------

        if (!remove) {
            printf("%s = %s %s %s\n",
                   code[i].res, code[i].op, code[i].arg1, code[i].arg2);
        } else {
            printf("Removed: %s %s %s %s\n",
                   code[i].res, code[i].op, code[i].arg1, code[i].arg2);
        }
    }

    return 0;
}
