#include <iostream>
using namespace std;

int main() {
    int arr[10], i, j, temp;

    for(i = 0; i < 10; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    for(i = 0; i < 9; i++) {
        for(j = i + 1; j < 10; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "The 4 minimum elements are:" << endl;
    for(i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
