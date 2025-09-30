#include <iostream>
using namespace std;

bool hasDuplicates(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {1, 3, 5, 7, 3, 9};
    int n = 6;

    if(hasDuplicates(arr, n)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
