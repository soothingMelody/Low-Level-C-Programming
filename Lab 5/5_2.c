#include <stdio.h>

#define MAX_ROWS 15
#define MAX_COLS 15
//Function to calculate the arrays 
void calculateArrays(int A[][MAX_COLS], int B[][MAX_COLS], int R[][MAX_COLS], int P[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == B[i][j]) {
                R[i][j] = 1;
            } else {
                R[i][j] = 0;
            }

            if (A[i][j] > B[i][j]) {
                P[i][j] = 1;
            } else {
                P[i][j] = 0;
            }
        }
    }
}
//function to print out the arrays
void displayArray(int arr[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows (<= 15): ");
    scanf("%d", &rows);
    printf("Enter the number of columns (<= 15): ");
    scanf("%d", &cols);

    int A[MAX_ROWS][MAX_COLS];
    int B[MAX_ROWS][MAX_COLS];
    int R[MAX_ROWS][MAX_COLS];
    int P[MAX_ROWS][MAX_COLS];

    printf("Enter the elements of array A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of array B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    calculateArrays(A, B, R, P, rows, cols);
    
    //displaying the arrays
    printf("\nArray R:\n");
    displayArray(R, rows, cols);

    printf("\nArray P:\n");
    displayArray(P, rows, cols);

    return 0;
}