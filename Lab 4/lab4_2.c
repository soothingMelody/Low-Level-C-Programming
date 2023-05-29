#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Exercise 2

void convertFile(const char* fileName, int formatChoice) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[1000];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (formatChoice == 1) {
            int indentation = 0;
            for (size_t i = 0; i < strlen(line); i++) {
                if (line[i] == '*') {
                    indentation++;
                } else {
                    break;
                }
            }
            for (int i = 0; i < indentation; i++) {
                printf("%d.", lineNumber);
            }
            printf(" %s", line + indentation);
        } else if (formatChoice == 2) {
            int indentation = 0;
            for (size_t i = 0; i < strlen(line); i++) {
                if (line[i] == '*') {
                    indentation++;
                } else {
                    break;
                }
            }
            for (int i = 0; i < indentation; i++) {
                printf("%c.", 'A' + lineNumber - 1);
            }
            printf(" %s", line + indentation);
        }

        lineNumber++;
    }

    fclose(file);
}

int main() {
    char fileName[100];
    int formatChoice;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    printf("Choose the format for conversion (1 or 2): ");
    scanf("%d", &formatChoice);

    convertFile(fileName, formatChoice);

    return 0;
}