#include <stdio.h>
#include <string.h>

int main() {
    char lhs[10], op[3], arg1[10], arg2[10];
    char line[50];
    
    printf("Enter TAC statements (type 'exit' to stop):\n");

    while (1) {

        // Read a line of TAC
        printf("\nTAC> ");
        fgets(line, sizeof(line), stdin);

        // Exit condition
        if (strncmp(line, "exit", 4) == 0)
            break;

        // Case: x = y op z
        if (sscanf(line, "%s = %s %s %s", lhs, arg1, op, arg2) == 4) {

            // Remove trailing newline if any
            arg2[strcspn(arg2, "\n")] = 0;

            printf("\nGenerated Assembly:\n");

            // MOV R1, y
            printf("MOV R1, %s\n", arg1);

            // op R1, z
            if (strcmp(op, "+") == 0)
                printf("ADD R1, %s\n", arg2);
            else if (strcmp(op, "-") == 0)
                printf("SUB R1, %s\n", arg2);
            else if (strcmp(op, "*") == 0)
                printf("MUL R1, %s\n", arg2);
            else if (strcmp(op, "/") == 0)
                printf("DIV R1, %s\n", arg2);
            else
                printf("; Unsupported operator %s\n", op);

            // Store result
            printf("MOV %s, R1\n", lhs);
        }

        // Case: x = y
        else if (sscanf(line, "%s = %s", lhs, arg1) == 2) {

            // Remove newline
            arg1[strcspn(arg1, "\n")] = 0;

            printf("\nGenerated Assembly:\n");
            printf("MOV %s, %s\n", lhs, arg1);
        }

        else {
            printf("Invalid TAC format!\n");
        }
    }

    return 0;
}
