#include <stdio.h>
#include <stdlib.h>

void readMatrixFromFile(const char *filename, int matrix[][10], int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    
    fscanf(file, "%d %d", rows, cols);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    
    fclose(file);
}

void addMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void writeMatrixToFile(const char *filename, int matrix[][10], int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows, cols;

    // Read first matrix from file
    readMatrixFromFile("matrix1.txt", matrix1, &rows, &cols);
    
    // Read second matrix from file
    readMatrixFromFile("matrix2.txt", matrix2, &rows, &cols);
    
    // Add the two matrices
    addMatrices(matrix1, matrix2, result, rows, cols);
    
    // Write the result to a file
    writeMatrixToFile("result.txt", result, rows, cols);

    printf("Matrices added and result saved to result.txt\n");
    
    return 0;
}
