#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

int partitionRandom(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int partitionMiddle(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int partitionMedian(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    int medianIndex;

    if ((a > b && a < c) || (a < b && a > c))
        medianIndex = low;
    else if ((b > a && b < c) || (b < a && b > c))
        medianIndex = mid;
    else
        medianIndex = high;

    swap(arr[medianIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int type) {
    if (low >= high) return;

    int pivotIndex;
    if (type == 1)
        pivotIndex = partitionFirst(arr, low, high);
    else if (type == 2)
        pivotIndex = partitionRandom(arr, low, high);
    else if (type == 3)
        pivotIndex = partitionMiddle(arr, low, high);
    else
        pivotIndex = partitionMedian(arr, low, high);

    quickSort(arr, low, pivotIndex - 1, type);
    quickSort(arr, pivotIndex + 1, high, type);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));

    int arr1[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original array:\n";
    printArray(arr1, n);

    int arr2[n], arr3[n], arr4[n], arr5[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
        arr5[i] = arr1[i];
    }

    comparisons = 0;
    quickSort(arr2, 0, n - 1, 1);
    cout << "\nPivot: First element\n";
    printArray(arr2, n);
    cout << "Comparisons: " << comparisons << endl;

    comparisons = 0;
    quickSort(arr3, 0, n - 1, 2);
    cout << "\nPivot: Random element\n";
    printArray(arr3, n);
    cout << "Comparisons: " << comparisons << endl;

    comparisons = 0;
    quickSort(arr4, 0, n - 1, 3);
    cout << "\nPivot: Middle element\n";
    printArray(arr4, n);
    cout << "Comparisons: " << comparisons << endl;

    comparisons = 0;
    quickSort(arr5, 0, n - 1, 4);
    cout << "\nPivot: Median-of-three\n";
    printArray(arr5, n);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}
