#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[] = {"banana", "apple", "cherry", "date", "grape"};
    int n = 5, i, j;
    string temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
