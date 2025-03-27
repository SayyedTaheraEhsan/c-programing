#include <iostream>
using namespace std;

int main() {
    int n;

    // Take matrix size input
    cout << "Enter the size of the matrix: ";
    cin >> n;

    // Create identity matrix
    int matrix[n][n];

    // Fill matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
