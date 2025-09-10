#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int** data;

public:
    Matrix(int r, int c, int val = 0) {
        rows = r; cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) data[i][j] = val;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    void resize(int r, int c, int val = 0) {
        Matrix temp(r, c, val);
        for (int i = 0; i < min(rows, r); i++)
            for (int j = 0; j < min(cols, c); j++)
                temp.data[i][j] = data[i][j];
        *this = temp;
    }

    void transpose() {
        Matrix temp(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.data[j][i] = data[i][j];
        *this = temp;
    }

    void addTwoToOddIndex() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (i % 2 || j % 2) data[i][j] += 2;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << "\n";
        }
    }

    void operator=(const Matrix& other) {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
        rows = other.rows; cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        }
    }
};

int main() {
    Matrix m(2, 3, 1);
    cout << "Initial:\n"; m.print();

    m.resize(3, 4, 0);
    cout << "\nAfter resize:\n"; m.print();

    m.transpose();
    cout << "\nAfter transpose:\n"; m.print();

    m.addTwoToOddIndex();
    cout << "\nAfter adding 2 to odd indices:\n"; m.print();
}
