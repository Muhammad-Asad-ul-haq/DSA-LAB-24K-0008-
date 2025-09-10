#include <iostream>
using namespace std;

int main() {
    int depts;
    cin >> depts;

    int* students = new int[depts];
    int*** marks = new int**[depts];

    for (int d = 0; d < depts; d++) {
        cin >> students[d];
        marks[d] = new int*[students[d]];
        for (int s = 0; s < students[d]; s++) {
            marks[d][s] = new int[5];
            for (int sub = 0; sub < 5; sub++)
                cin >> marks[d][s][sub];
        }
    }

    for (int d = 0; d < depts; d++) {
        int firstTotal = 0;
        for (int sub = 0; sub < 5; sub++)
            firstTotal += marks[d][0][sub];

        int maxT = firstTotal;
        int minT = firstTotal;
        int sumAll = firstTotal;

        for (int s = 1; s < students[d]; s++) {
            int total = 0;
            for (int sub = 0; sub < 5; sub++)
                total += marks[d][s][sub];

            if (total > maxT)
                maxT = total;   
            if (total < minT)
                minT = total;   

            sumAll += total;
        }

        double avg = (double)sumAll / students[d];
        cout << "Dept " << d + 1
             << ": Highest = " << maxT
             << ", Lowest = " << minT
             << ", Average = " << avg << endl;
    }

    for (int d = 0; d < depts; d++) {
        for (int s = 0; s < students[d]; s++)
            delete[] marks[d][s];
        delete[] marks[d];
    }
    delete[] marks;
    delete[] students;
}
