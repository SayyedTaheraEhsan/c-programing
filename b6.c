#include <iostream>
using namespace std;

int main() {
    int n;

    // Taking the size of the matrix as input
    cout << "Enter the size of the matrix: ";
    cin >> n;

    // Creating a 2D array (matrix) of size n x n
    int matrix[n][n];

    // Initializing the matrix to be upper triangular
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                matrix[i][j] = 0;  // Setting the lower triangle elements to 0
            } else {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    // Printing the upper triangular matrix
    cout << "The upper triangular matrix is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
