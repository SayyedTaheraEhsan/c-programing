#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> mat;
    int rows, cols;

public:
    // Constructor to initialize matrix with given rows and columns
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(rows, vector<int>(cols, 0));
    }

    // Function to set a value at a specific position
    void setValue(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            mat[r][c] = value;
        }
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j]
