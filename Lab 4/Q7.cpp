#include <iostream>
#include <string>
using namespace std;

int linearSearch(string arr[], int n, string key, int &steps) {
    steps = 0;
    for(int i = 0; i < n; i++) {
        steps++;
        if(arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(string arr[], int n, string key, int &steps) {
    int low = 0, high = n - 1, mid;
    steps = 0;
    while(low <= high) {
        steps++;
        mid = (low + high) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    string arr[] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};
    int n = 10;

    string keys[] = {"Aftab", "Rizwan", "Tariq"};

    for(int k = 0; k < 3; k++) {
        int steps1, steps2;
        int index1 = linearSearch(arr, n, keys[k], steps1);
        int index2 = binarySearch(arr, n, keys[k], steps2);

        cout << "Searching for " << keys[k] << endl;
        if(index1 != -1) cout << "Linear: Found at " << index1 << " in " << steps1 << " steps" << endl;
        else cout << "Linear: Not found in " << steps1 << " steps" << endl;

        if(index2 != -1) cout << "Binary: Found at " << index2 << " in " << steps2 << " steps" << endl;
        else cout << "Binary: Not found in " << steps2 << " steps" << endl;

        cout << endl;
    }
    return 0;
}
