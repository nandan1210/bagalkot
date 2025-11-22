#include <stdio.h>

float add(int x, int y) {
    return x + y; // int promoted to float
}

int main() {
    int result;
    result = add(2, 3); // Warning: assigning float to int
    printf("Result = %d\n", result); // 5 (truncated)
    return 0;
}
