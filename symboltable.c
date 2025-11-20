#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[10];
};

struct Symbol table[50];
int count = 0;

void insert() {
    char name[20], type[10];

    printf("Enter identifier name: ");
    scanf("%s", name);

    // Check duplicate
    for(int i = 0; i < count; i++) {
        if(strcmp(table[i].name, name) == 0) {
            printf("Error: Duplicate identifier!\n");
            return;
        }
    }

    printf("Enter type: ");
    scanf("%s", type);

    // Insert entry
    strcpy(table[count].name, name);
    strcpy(table[count].type, type);

    count++;

    printf("Inserted successfully!\n");
}

void display() {
    printf("\n----- SYMBOL TABLE -----\n");
    printf("Name\tType\n");
    printf("------------------------\n");

    for(int i = 0; i < count; i++)
        printf("%s\t%s\n", table[i].name, table[i].type);
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Insert\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            insert();
        else if(choice == 2)
            display();
        else
            break;
    }
    
    return 0;
}
