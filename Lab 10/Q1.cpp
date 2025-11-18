#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int largest = i;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void update_key(int i, int new_val) {
        heap[i] = new_val;
        heapifyUp(i);
        heapifyDown(i);
    }

    void delete_index(int i) {
        heap[i] = heap.back();
        heap.pop_back();
        heapifyUp(i);
        heapifyDown(i);
    }

    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    int arr[] = {8,7,6,5,4};
    for (int x : arr) h.insert(x);

    h.printHeap();

    h.update_key(3, 10);
    h.printHeap();

    h.delete_index(1);
    h.printHeap();

    return 0;
}
