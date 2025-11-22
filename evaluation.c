#include <stdio.h>

int main() {
    // Step 1: Define variables
    int a;          // id 'a'
    int number1 = 5; // first number
    int number2 = 3; // second number

    // Step 2: Evaluate expression using semantic action (E -> E + T)
    int E = number1 + number2;

    // Step 3: Perform assignment (S -> id = E)
    a = E;

    // Step 4: Print the result
    printf("Value of a: %d\n", a);

    return 0;
}
