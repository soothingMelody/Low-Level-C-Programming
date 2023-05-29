///Exercise 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPUTERS 100

typedef struct {
    char* name;
    char* brand;
    float price;
} Computer;

void addComputer(Computer* computers[], int* count) {
    if (*count == MAX_COMPUTERS) {
        printf("Cannot add more computers. The list is full.\n");
        return;
    }

    Computer* new_computer = malloc(sizeof(Computer));

    char name[100], brand[100];
    float price;

    printf("Enter the computer name: ");
    scanf("%s", name);

    printf("Enter the computer brand: ");
    scanf("%s", brand);

    printf("Enter the computer price: ");
    scanf("%f", &price);

    new_computer->name = strdup(name);
    new_computer->brand = strdup(brand);
    new_computer->price = price;

    computers[*count] = new_computer;
    (*count)++;

    printf("Computer added successfully.\n");
}

void searchComputer(Computer* computers[], int count) {
    char search_name[100];

    printf("Enter the name of the computer to search: ");
    scanf("%s", search_name);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(computers[i]->name, search_name) == 0) {
            printf("Computer found:\n");
            printf("Name: %s\n", computers[i]->name);
            printf("Brand: %s\n", computers[i]->brand);
            printf("Price: %.2f\n", computers[i]->price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Computer not found.\n");
    }
}

void removeComputer(Computer* computers[], int* count) {
    char remove_name[100];

    printf("Enter the name of the computer to remove: ");
    scanf("%s", remove_name);

    int found = 0;

    for (int i = 0; i < *count; i++) {
        if (strcmp(computers[i]->name, remove_name) == 0) {
            free(computers[i]->name);
            free(computers[i]->brand);
            free(computers[i]);
            
            for (int j = i; j < (*count) - 1; j++) {
                computers[j] = computers[j + 1];
            }
            
            (*count)--;
            found = 1;
            printf("Computer removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Computer not found.\n");
    }
}

void displayComputers(Computer* computers[], int count) {
    if (count == 0) {
        printf("No computers in the list.\n");
        return;
    }

    printf("List of computers:\n");

    for (int i = 0; i < count; i++) {
        printf("Computer %d:\n", i + 1);
        printf("Name: %s\n", computers[i]->name);
        printf("Brand: %s\n", computers[i]->brand);
        printf("Price: %.2f\n", computers[i]->price);
        printf("\n");
    }
}

void freeComputers(Computer* computers[], int count) {
    for (int i = 0; i < count; i++) {
        free(computers[i]->name);
        free(computers[i]->brand);
        free(computers[i]);
    }
}

int main() {
    Computer* computers[MAX_COMPUTERS];
    int count = 0;

    char command;

    while (1) {
        printf("Enter a command (N|n: add, S|s: search, R|r: remove, D|d: display, Q|q: quit): ");
        scanf(" %c", &command);

        if (command == 'N' || command == 'n') {
            addComputer(computers, &count);
        } else if (command == 'S' || command == 's') {
            searchComputer(computers, count);
        } else if (command == 'R' || command == 'r') {
            removeComputer(computers, &count);
        } else if (command == 'D' || command == 'd') {
            displayComputers(computers, count);
        } else if (command == 'Q' || command == 'q') {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }

        printf("\n");
    }

    freeComputers(computers, count);

    return 0;
}