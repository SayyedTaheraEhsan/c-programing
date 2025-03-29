#include <iostream>
#include <vector>

using namespace std;

// Function to perform back substitution
vector<double> backSubstitution(vector<vector<double>>& matrix, vector<double>& b) {
    int n = matrix.size();
    vector<double> x(n); // Solution vector

    // Perform back substitution
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i]; // Set the right-hand side value

        // Subtract the already solved unknowns
        for (int j = i + 1; j < n; ++j) {
            x[i] -= matrix[i][j] * x[j];
        }

        // Divide by the diagonal element
        x[i] /= matrix[i][i];
    }

    return x;
}

int main() {
    int n;

    // Input the size of the matrix
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    vector<double> b(n);

    // Input the upper triangular matrix (coefficients)
    cout << "Enter the elements of the upper triangular matrix (row by row):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Input the right-hand side vector
    cout << "Enter the elements of the right-hand side vector (b):\n";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Perform back substitution to find the solution
    vector<double> solution = backSubstitution(matrix, b);

    // Output the solution
    cout << "The solution is:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
