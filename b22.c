#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int matrix1[100][100], matrix2[100][100], sum[100][100];

    // Input matrix 1
    cout << "Enter elements of Matrix 1:\n";
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }

    // Input matrix 2
    cout << "Enter elements of Matrix 2:\n";
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }

    // Adding matrices
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            sum[i][j] = matrix1[i][j] + matrix2[i][j];

    // Display result
    cout << "\nSum of matrices:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j)
            cout << sum[i][j] << " ";
        cout << endl;
    }

    return 0;
}
