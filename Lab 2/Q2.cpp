#include <iostream>
using namespace std;

int main() {
    int students = 5, subjects = 4;
    int** marks = new int*[students];
    for (int i = 0; i < students; i++)
        marks[i] = new int[subjects];

    for (int i = 0; i < students; i++)
        for (int j = 0; j < subjects; j++)
            cin >> marks[i][j];

    int topperIndex = 0, maxTotal = -1;
    for (int i = 0; i < students; i++) {
        int total = 0;
        for (int j = 0; j < subjects; j++)
            total += marks[i][j];
        cout << "Student " << i + 1 << " Total = " << total << endl;
        if (total > maxTotal) {
            maxTotal = total;
            topperIndex = i;
        }
    }

    for (int j = 0; j < subjects; j++) {
        int sum = 0;
        for (int i = 0; i < students; i++)
            sum += marks[i][j];
        cout << "Subject " << j + 1 << " Avg = " << (double)sum / students << endl;
    }

    cout << "Topper = Student " << topperIndex + 1 << " with " << maxTotal << endl;

    for (int i = 0; i < students; i++)
        delete[] marks[i];
    delete[] marks;
}
