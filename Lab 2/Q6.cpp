#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    int* seats = new int[rows];          
    string** chart = new string*[rows];  

   
    for (int i = 0; i < rows; i++) {
        cout << "Enter number of seats in row " << i + 1 << ": ";
        cin >> seats[i];
        chart[i] = new string[seats[i]]; 
    }

   
    for (int i = 0; i < rows; i++) {
        cout << "\nEnter names of seats for row " << i + 1 << ":\n";
        for (int j = 0; j < seats[i]; j++) {
            cout << " Seat " << j + 1 << ": ";
            cin >> chart[i][j];
        }
    }

    
    cout << "\nConference Seating Chart:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < seats[i]; j++) {
            cout << chart[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < rows; i++)
        delete[] chart[i];
    delete[] chart;
    delete[] seats;

    return 0;
}
