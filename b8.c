#include <iostream>
using namespace std;

int main() {
    int n;

    // Taking the size of the matrix
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int matrix[n][n];

    // Taking input for the matrix elements
    cout << "Enter the elements of the matrix: \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Printing the upper triangular matrix
    cout << "\nUpper triangular matrix: \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j) {
                cout << matrix[i][j] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
