#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10   // number of buckets

// Structure for each symbol
struct Symbol {
    char name[20];
    char type[10];
    struct Symbol* next;   // for chaining
};

// Hash table: array of pointers
struct Symbol* table[TABLE_SIZE];

// Hash Function
int hash(char* name) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++)
        sum += name[i];

    return sum % TABLE_SIZE;
}

// Insert into Symbol Table
void insert() {
    char name[20], type[10];
    printf("Enter identifier name: ");
    scanf("%s", name);

    int index = hash(name);

    // Check duplicate
    struct Symbol* temp = table[index];
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Duplicate Entry! Not inserted.\n");
            return;
        }
        temp = temp->next;
    }

    // Create new node
    struct Symbol* newSymbol = (struct Symbol*)malloc(sizeof(struct Symbol));
    strcpy(newSymbol->name, name);

    printf("Enter type: ");
    scanf("%s", type);
    strcpy(newSymbol->type, type);

    newSymbol->next = table[index];
    table[index] = newSymbol;

    printf("Inserted Successfully!\n");
}

// Search Symbol
void search() {
    char name[20];
    printf("Enter name to search: ");
    scanf("%s", name);

    int index = hash(name);

    struct Symbol* temp = table[index];
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("FOUND → Name: %s, Type: %s\n", temp->name, temp->type);
            return;
        }
        temp = temp->next;
    }

    printf("NOT FOUND!\n");
}

// Display Symbol Table
void display() {
    printf("\n------ SYMBOL TABLE (With Hashing) ------\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);

        struct Symbol* temp = table[i];
        if (temp == NULL) {
            printf("EMPTY");
        }

        while (temp != NULL) {
            printf(" -> [%s, %s]", temp->name, temp->type);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main Menu
int main() {
    int choice;

    // Initialize table
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            insert();
        else if (choice == 2)
            search();
        else if (choice == 3)
            display();
        else
            break;
    }

    return 0;
}
