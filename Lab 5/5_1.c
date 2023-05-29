#include <stdio.h>
#include <stdlib.h>

// function to find the maximum element
int findMaximum(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to find the minimum element
int findMinimum(int* array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// function to compute the arithmetic mean
int computeMean(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int* T = (int*)malloc(n * sizeof(int)); // Dynamically allocate the array

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
    }

    // Function pointers
    int (*funcPtr[3])(int*, int) = {findMaximum, findMinimum, computeMean};

    // Menu loop
    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("0: Find the maximum element\n");
        printf("1: Find the minimum element\n");
        printf("2: Compute the arithmetic mean\n");
        printf("Any other value will result in the program automatically shutting down.\n");
        printf("Enter your choice (0-2): ");
        scanf("%d", &choice);

        // Check if the choice is within the valid range
        if (choice >= 0 && choice <= 2) {
            // Call selected function using function pointer
            int result = funcPtr[choice](T, n);

            if (choice == 0)
                printf("Maximum element: %d\n", result);
            else if (choice == 1)
                printf("Minimum element: %d\n", result);
            else
                printf("Arithmetic mean: %.2f\n", (double)result);
        } else {
            break;
        }
    }

    free(T);

    return 0;
}