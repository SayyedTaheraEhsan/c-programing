#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;

    // Input for matrix dimensions
    printf("Enter the rows of matrix: ");
    scanf("%d", &r);
    printf("Enter the columns of matrix: ");
    scanf("%d", &c);

    // Dynamic memory allocation for matrices
    int **mat1 = (int **)malloc(r * sizeof(int *));
    int **mat2 = (int **)malloc(r * sizeof(int *));
    int **sum = (int **)malloc(r * sizeof(int *));
    int **sub = (int **)malloc(r * sizeof(int *));

    if (mat1 == NULL || mat2 == NULL || sum == NULL || sub == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < r; i++) {
        mat1[i] = (int *)malloc(c * sizeof(int));
        mat2[i] = (int *)malloc(c * sizeof(int));
        sum[i] = (int *)malloc(c * sizeof(int));
        sub[i] = (int *)malloc(c * sizeof(int));

        if (mat1[i] == NULL || mat2[i] == NULL || sum[i] == NULL || sub[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    // Input for first matrix
    printf("Enter first Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input for second matrix
    printf("Enter second Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Display first matrix
    printf("First Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }

    // Display second matrix
    printf("Second Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }

    // Matrix Addition
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Display sum matrix
    printf("Matrix Addition:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    // Matrix Subtraction
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sub[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    // Display subtraction matrix
    printf("Matrix Subtraction:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", sub[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < r; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(sum[i]);
        free(sub[i]);
    }
    free(mat1);
    free(mat2);
    free(sum);
    free(sub);

    return 0;
}
