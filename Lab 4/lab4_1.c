#include <stdio.h>

//Exercise 1

int countCharacterOccurences(const char* fileName, char character) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return -1;
    }

    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == character) {
            count++;
        }
    }

    fclose(file);

    return count;
}

int main() {
    char fileName[100];
    char character;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    printf("Enter the character to count: ");
    scanf(" %c", &character);

    int occurrences = countCharacterOccurences(fileName, character);
    if (occurrences >= 0) {
        printf("Occurrences of '%c' in the file: %d\n", character, occurrences);
    }

    return 0;
}