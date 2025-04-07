#include <iostream>
using namespace std;

// Function to input matrix elements
void inputMatrix(int matrix[3][3], int rows, int cols) {
    cout << "Enter elements of matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function for matrix addition
void addMatrices(int mat1[3][3], int mat2[3][3], int result[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function for matrix subtraction
void subtractMatrices(int mat1[3][3], int mat2[3][3], int result[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrices(int mat1[3][3], int mat2[3][3], int result[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[3][3], mat2[3][3], result[3][3];
    int rows = 3, cols = 3;
