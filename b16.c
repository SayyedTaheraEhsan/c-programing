#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 10;

// Function to perform Cholesky decomposition
bool choleskyDecomposition(double A[MAX][MAX], double L[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;

            if (j == i) { // Diagonal elements
                for (int k = 0; k < j; k++)
                    sum += pow(L[j][k], 2);
                double diag = A[j][j] - sum;
                if (diag <= 0) return false; // Not positive-definite
                L[j][j] = sqrt(diag);
            } else {
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
    return true;
}

// Function to print matrix
void printMatrix(double mat[MAX][MAX], int n) {
    for (int i = 0; i <
