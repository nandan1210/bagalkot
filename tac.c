#include <stdio.h>

int main() {

    // Input variables (you may accept user input also)
    int a = 5, b = 3, c = 8, d = 2;

    // Temporary variables used in TAC
    int t1 = a + b;     // t1 = a + b
    int t2 = c - d;     // t2 = c - d
    int t3 = t1 * t2;   // t3 = t1 * t2
    int x  = t3;        // x = t3

    printf("=== THREE ADDRESS CODE (TAC) ===\n");
    printf("t1 = a + b\n");
    printf("t2 = c - d\n");
    printf("t3 = t1 * t2\n");
    printf("x  = t3\n\n");

    printf("=== QUADRUPLES ===\n");
    printf("Index | op | arg1 | arg2 | result\n");
    printf("-----------------------------------\n");
    printf("0     |  + |   a  |   b  |  t1\n");
    printf("1     |  - |   c  |   d  |  t2\n");
    printf("2     |  * |  t1  |  t2  |  t3\n");
    printf("3     |  = |  t3  |   -  |  x\n\n");

    printf("Computed Value of x = %d\n", x);

    return 0;
}
