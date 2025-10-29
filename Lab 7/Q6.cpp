#include <iostream>
using namespace std;

void mergeArrays(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
        arr[k++] = (leftArr[i] < rightArr[j]) ? leftArr[i++] : rightArr[j++];

    while (i < n1)
        arr[k++] = leftArr[i++];

    while (j < n2)
        arr[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeArrays(arr, left, mid, right);
}

void countingSort(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr1[10] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420};
    int arr2[10] = {66, 3, 17, 45, 123, 77, 88, 900, 120, 10};
    int combined[20];

    for (int i = 0; i < 10; i++)
        combined[i] = arr1[i];
    for (int i = 0; i < 10; i++)
        combined[10 + i] = arr2[i];

    int n = 20;

    cout << "Combined array before sorting:\n";
    for (int i = 0; i < n; i++)
        cout << combined[i] << " ";
    cout << "\n\n";

    cout << "Sorted array using Merge Sort:\n";
    mergeSort(combined, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << combined[i] << " ";
    cout << "\n\n";

    int arr3[20];
    for (int i = 0; i < 10; i++)
        arr3[i] = arr1[i];
    for (int i = 0; i < 10; i++)
        arr3[10 + i] = arr2[i];

    radixSort(arr3, n);

    cout << "Sorted array using Radix Sort:\n";
    for (int i = 0; i < n; i++)
        cout << arr3[i] << " ";
    cout << endl;

    return 0;
}
