#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Exercise 3

void printColumnStatistics(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    int rowCount = 0;
    int columnCount = 0;
    double columnSum[100] = {0.0};

    char line[1000];
    while (fgets(line, sizeof(line), file) != NULL) {
        rowCount++;

        int column = 0;
        char* token = strtok(line, " ");
        while (token != NULL) {
            double value = atof(token);
            columnSum[column] += value;
            column++;

            token = strtok(NULL, " ");
        }

        if (column > columnCount) {
            columnCount = column;
        }
    }

    fclose(file);

    printf("Sum: ");
    for (int i = 0; i < columnCount; i++) {
        printf("%.2f ", columnSum[i]);
    }
    printf("\n");

    printf("Average: ");
    for (int i = 0; i < columnCount; i++) {
        double average = columnSum[i] / rowCount;
        printf("%.2f ", average);
    }
    printf("\n");
}

int main() {
    char fileName[100];

    printf("Enter the file name: ");
    scanf("%s", fileName);

    printColumnStatistics(fileName);

    return 0;
}