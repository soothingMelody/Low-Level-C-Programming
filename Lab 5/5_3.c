#include <stdio.h>
#include <stdlib.h>

#define MAX_MEASUREMENTS 4

//Defining the structure for Series
typedef struct {
    int seriesNumber;
    double measurements[MAX_MEASUREMENTS];
    int code;
} Series;

//The function to calculate a mean average
double calculateMean(double measurements[]) {
    double sum = 0.0;
    for (int i = 0; i < MAX_MEASUREMENTS; i++) {
        sum += measurements[i];
    }
    return sum / MAX_MEASUREMENTS;
}

//finding max
double findMaximum(double measurements[]) {
    double max = measurements[0];
    for (int i = 1; i < MAX_MEASUREMENTS; i++) {
        if (measurements[i] > max) {
            max = measurements[i];
        }
    }
    return max;
}

//finding min
double findMinimum(double measurements[]) {
    double min = measurements[0];
    for (int i = 1; i < MAX_MEASUREMENTS; i++) {
        if (measurements[i] < min) {
            min = measurements[i];
        }
    }
    return min;
}

void processSeries(Series series[], int numSeries) {
    double (*processFunc[3])(double[]) = {calculateMean, findMaximum, findMinimum};

    FILE *outputFile;
    outputFile = fopen("Results.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating output file.\n");
        return;
    }

    for (int i = 0; i < numSeries; i++) {
        double result = processFunc[series[i].code](series[i].measurements);
        fprintf(outputFile, "%d\n", series[i].seriesNumber);
        fprintf(outputFile, "%.2f\n", result);
        fprintf(outputFile, "%d\n", series[i].code);
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);
}

int main() {
    FILE *inputFile;
    int numSeries;

    // Open the input file
    inputFile = fopen("Calculations.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read the number of series
    fscanf(inputFile, "%d", &numSeries);
    Series *series = (Series *)malloc(numSeries * sizeof(Series));

    // Read series data from the input file
    for (int i = 0; i < numSeries; i++) {
        fscanf(inputFile, "%d", &series[i].seriesNumber);
        for (int j = 0; j < MAX_MEASUREMENTS; j++) {
            fscanf(inputFile, "%lf", &series[i].measurements[j]);
        }
        fscanf(inputFile, "%d", &series[i].code);
    }

    fclose(inputFile);

    processSeries(series, numSeries);

    free(series);

    return 0;
}