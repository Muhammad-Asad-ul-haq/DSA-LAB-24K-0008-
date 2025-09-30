#include <iostream>
using namespace std;

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = 6, i, j, key, num;

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Enter last two digits of roll number: ";
    cin >> num;

    bool found = false;
    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            found = true;
            break;
        }
    }

    if(!found) {
        int newArr[7];
        int k = 0;
        bool placed = false;
        for(i = 0; i < n; i++) {
            if(!placed && num < arr[i]) {
                newArr[k++] = num;
                placed = true;
            }
            newArr[k++] = arr[i];
        }
        if(!placed) newArr[k++] = num;
        n++;
        for(i = 0; i < n; i++) arr[i] = newArr[i];
    }

    int low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == num) {
            cout << "Found " << num << " at index " << mid << endl;
            break;
        }
        else if(arr[mid] < num) low = mid + 1;
        else high = mid - 1;
    }

    cout << "Sorted array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
