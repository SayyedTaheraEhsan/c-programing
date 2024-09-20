#include <stdio.h>

#define ROWS 3
#define COLS 4

void printRowMajor(int array[ROWS][COLS]) {
    printf("Row-major order:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void printColumnMajor(int array[ROWS][COLS]) {
    printf("Column-major order:\n");
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declare and initialize a 2D array
    int array[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Print in row-major order
    printRowMajor(array);
    
    // Print in column-major order
    printColumnMajor(array);

    // Accessing elements using row-major indexing
    printf("\nAccessing elements using row-major indexing:\n");
    for (int i = 0; i < ROWS * COLS; i++) {
        int row = i / COLS;
        int col = i % COLS;
        printf("%d ", array[row][col]);
    }
    printf("\n");

    // Accessing elements using column-major indexing
    printf("\nAccessing elements using column-major indexing:\n");
    for (int i = 0; i < ROWS * COLS; i++) {
        int col = i / ROWS;
        int row = i % ROWS;
        printf("%d ", array[row][col]);
    }
    printf("\n");

    return 0;
}
