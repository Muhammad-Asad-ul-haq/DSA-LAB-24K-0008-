#include <iostream>
using namespace std;

class Friends {
private:
    bool **data;
    int n;

public:
    Friends(int size) {
        n = size;
        data = new bool*[n];
        for (int i = 0; i < n; i++) {
            data[i] = new bool[n];
        }

       
        bool m[5][5] = {
            {0,1,0,1,1},
            {1,0,1,0,1},
            {0,1,0,0,0},
            {1,0,0,0,1},
            {1,1,0,1,0}
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = m[i][j];
            }
        }
    }

    void common(int a, int b) {
        bool found = false;
        cout << "Common friends: ";
        for (int i = 0; i < n; i++) {
            if (data[a][i] && data[b][i]) {
                cout << i << " ";
                found = true;
            }
        }
        if (!found) cout << "None";
        cout << endl;
    }

    ~Friends() {
        for (int i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    Friends f(5);

    int x, y;
    cout << "Enter two numbers (0-4): ";
    cin >> x >> y;

    f.common(x, y);

    return 0;
}
