#include <stdio.h>

int main() {

    // Input values (optional, can be changed)
    int m = 10, n = 4, u = 3, v = 5;

    // Temporary computations
    int t0 = m - n;     // (0)
    int t1 = u + v;     // (1)
    int t2 = t0 * t1;   // (2)
    int p  = t2;        // (3)

    printf("=== TRIPLE REPRESENTATION ===\n");
    printf("Index | Op | Arg1 | Arg2\n");
    printf("-----------------------------\n");

    printf("(0)   |  -  |  m   |  n\n");
    printf("(1)   |  +  |  u   |  v\n");
    printf("(2)   |  *  | (0)  | (1)\n");
    printf("(3)   |  =  | (2)  |  -\n\n");

    printf("Final value of p = %d\n", p);

    return 0;
}
