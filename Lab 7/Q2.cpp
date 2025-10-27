#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp, bool ascending) {
    int* sorted = new int[n];
    int freq[10] = {0};

    for (int i = 0; i < n; i++)
        freq[(arr[i] / exp) % 10]++;

    if (ascending) {
        for (int i = 1; i < 10; i++)
            freq[i] += freq[i - 1];
    } else {
        for (int i = 8; i >= 0; i--)
            freq[i] += freq[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        sorted[freq[digit] - 1] = arr[i];
        freq[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = sorted[i];

    delete[] sorted;
}

void radixSort(int arr[], int n, bool ascending) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp, ascending);

    if (!ascending) {
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }
}

int main() {
    int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    radixSort(arr, n, true);
    cout << "\n\nSorted in Ascending Order:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    radixSort(arr, n, false);
    cout << "\n\nSorted in Descending Order:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
