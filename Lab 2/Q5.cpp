#include <iostream>
using namespace std;

int main() {
    int depts = 4;
    int courses[4] = {3, 4, 2, 1};  

    double** gpa = new double*[depts];
    for (int i = 0; i < depts; i++)
        gpa[i] = new double[courses[i]];

    
    string deptNames[4] = {"SE", "AI", "CS", "DS"};
    for (int i = 0; i < depts; i++) {
        cout << "Enter GPAs for " << deptNames[i] << " (" << courses[i] << " courses):\n";
        for (int j = 0; j < courses[i]; j++)
            cin >> gpa[i][j];
    }

    
    cout << "\nGPAs of core courses:\n";
    for (int i = 0; i < depts; i++) {
        cout << deptNames[i] << ": ";
        for (int j = 0; j < courses[i]; j++)
            cout << gpa[i][j] << " ";
        cout << endl;
    }

    
    for (int i = 0; i < depts; i++)
        delete[] gpa[i];
    delete[] gpa;
}
