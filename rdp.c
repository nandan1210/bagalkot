#include <stdio.h>
#include <stdlib.h>
char *input;
void S() {
if (*input == 'a') {
input++;
S();
if (*input == 'b') input++;
else { printf("Rejected\n"); exit(0); }
}
}

int main() {
char str[20];
printf("Enter string: ");
scanf("%s", str);
input = str;
S();
if (*input == '\0') printf("Accepted\n");
else printf("Rejected\n");
return 0;
}
