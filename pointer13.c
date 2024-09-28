#include <stdio.h>
#include <stdlib.h>

// Function to check if the matrix is a Toeplitz matrix
int isToeplitzMatrix(int **matrix, int rows, int cols) {
    int i, j;

    // Check each diagonal starting from the first row
    for (i = 0; i < rows - 1; i++) {
        for (j = 0; j < cols - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return 0; // Not a Toeplitz matrix
            }
        }
    }

    // Check each diagonal starting from the first column
    for (j = 0; j < cols - 1; j++) {
        for (i = 0; i < rows - 1; i++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return 0; // Not a Toeplitz matrix
            }
        }
    }

    return 1; // Matrix is a Toeplitz matrix
}
 {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int **matrix;
    int i, j;

    // Read dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for the matrix
    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Read matrix elements
    printf("Enter elements for the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is:\n");
    printMatrix(matrix, rows, cols);

    // Check if the matrix is a Toeplitz matrix
    if (isToeplitzMatrix(matrix, rows, cols)) {
        printf("The matrix is a Toeplitz matrix.\n");
    } else {
        printf("The matrix is not a Toeplitz matrix.\n");
    }

    // Free allocated memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;

    // Check each diagonal starting from the first column
    for (j = 0; j < cols - 1; j++) {
        for (i = 0; i < rows - 1; i++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return 0; // Not a Toeplitz matrix
            }
        }
    }

    // Check each diagonal starting from the first column
    for (j = 0; j < cols - 1; j++) {
        for (i = 0; i < rows - 1; i++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return 0; // Not a Toeplitz matrix
            }
        }
    }

    // Check each diagonal starting from the first column
    for (j = 0; j < cols - 1; j++) {
        for (i = 0; i < rows - 1; i++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return 0; // Not a Toeplitz matrix
            }
        }
    }

    return 1; // Matrix is a Toeplitz matrix
}
