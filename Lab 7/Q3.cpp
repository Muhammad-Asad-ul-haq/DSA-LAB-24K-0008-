#include <iostream>
using namespace std;

struct Runner {
    string name;
    int time;
};

void mergeArrays(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner* leftArr = new Runner[n1];
    Runner* rightArr = new Runner[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (leftArr[i].time < rightArr[j].time) ? leftArr[i++] : rightArr[j++];
    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(Runner arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeArrays(arr, left, mid, right);
}

int main() {
    int n = 10;
    Runner runners[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name of runner " << i + 1 << ": ";
        cin >> runners[i].name;
        cout << "Enter finish time (in seconds): ";
        cin >> runners[i].time;
    }

    mergeSort(runners, 0, n - 1);

    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5; i++)
        cout << runners[i].name << " - " << runners[i].time << " seconds" << endl;

    return 0;
}
