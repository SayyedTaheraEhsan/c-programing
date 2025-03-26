#include <iostream>
using namespace std;

int main() {
    int m, n;

    // Get the dimensions of the matrices
    cout << "Enter the number of rows and columns of the matrices: ";
    cin >> m >> n;

    int matrix1[m][n], matrix2[m][n], result[m][n];

    // Input the elements of the first matrix
    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Input the elements of the second matrix
    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Perform matrix subtraction
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Display the result
    cout << "Resultant matrix after subtraction is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
