#include <stdio.h>

#define MAX 10

// Function to calculate determinant of matrix
float determinant(float matrix[MAX][MAX], int n) {
    float det = 0;
    float temp[MAX][MAX];

    if (n == 1) {
        return matrix[0][0];
    }

    // For each element of the first row, compute cofactor and determinant
    for (int p = 0; p < n; p++) {
        int h = 0;
        for (int i = 1; i < n; i++) {
            int w = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                temp[h][w++] = matrix[i][j];
            }
            h++;
        }
        det += (p % 2 == 0 ? 1 : -1) * matrix[0][p] * determinant(temp, n - 1);
    }

    return det;
}

// Function to get the solution using Cramer's Rule
void solveCramersRule(float matrix[MAX][MAX], float results[MAX], int n) {
    float det = determinant(matrix, n);

    if (det == 0) {
        printf("The system has no unique solution.\n");
        return;
    }

    float temp[MAX][MAX];
    float solutions[MAX];

    for (int i = 0; i < n; i++) {
        // Create the matrix with the ith column replaced by the results vector
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[j][k] = (k == i) ? results[j] : matrix[j][k];
            }
        }

        // Calculate the determinant of the modified matrix
        solutions[i] = determinant(temp, n) / det;
    }

    // Output the solution
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, solutions[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of variables (n): ");
    scanf("%d", &n);

    float matrix[MAX][MAX];
    float results[MAX];

    printf("Enter the coefficients of the augmented matrix (A|B):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
        scanf("%f", &results[i]);
    }

    solveCramersRule(matrix, results, n);

    return 0;
}
