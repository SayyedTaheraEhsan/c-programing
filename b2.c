#include <iostream>
using namespace std;

class Matrix {
public:
    int mat[2][2];  // 2x2 matrix for simplicity

    void input() {
        cout << "Enter 4 elements for 2x2 matrix:" << endl;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cin >> mat[i][j];
    }

    void display() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    Matrix add(const Matrix &m) {
        Matrix result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
        return result;
    }
};

int main() {
    Matrix m1, m2, m3;
    m1.input();
    m2.input();
    m3 = m1.add(m2);
    cout << "Sum of matrices:" << endl;
    m3.display();
    return 0;
}
