#include <stdio.h>

#define MAX 10

void gaussJordan(float matrix[MAX][MAX + 1], int n) {
    for (int i = 0; i < n; i++) {
        // Make the diagonal contain all 1s
        float diag = matrix[i][i];
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= diag;
        }

        // Make the other rows contain 0s in the current column
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = 0; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int n;
    float matrix[MAX][MAX + 1];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    gaussJordan(matrix, n);

    printf("The solutions are:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }

    return 0;
}
