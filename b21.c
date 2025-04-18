#include <iostream>
using namespace std;

class Matrix2x2 {
public:
    float m[2][2];

    void input() {
        cout << "Enter 4 elements of the 2x2 matrix:\n";
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> m[i][j];
    }

    void display() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }

    Matrix2x2 add(Matrix2x2 b) {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.m[i][j] = m[i][j] + b.m[i][j];
        return result;
    }

    Matrix2x2 subtract(Matrix2x2 b) {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.m[i][j] = m[i][j] - b.m[i][j];
        return result;
    }

    Matrix2x2 multiply(Matrix2x2 b) {
        Matrix2x2 result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j) {
                result.m[i][j] = 0;
                for (int k = 0; k < 2; ++k)
                    result.m[i][j] += m[i][k] * b.m[k][j];
            }
        return result;
    }
};

int main() {
    Matrix2x2 A, B, result;
    int choice;

    cout << "Matrix A:\n";
    A.input();
    cout << "Matrix B:\n";
    B.input();

    cout << "\nChoose operation:\n1. Add\n2. Subtract\n3. Multiply\nChoice: ";
    cin >> choice;

    switch (choice)
