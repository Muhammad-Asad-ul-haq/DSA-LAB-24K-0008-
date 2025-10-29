#include <iostream>
using namespace std;

struct Product {
    string name;
    string description;
    float price;
    bool available;
};

int partitionProducts(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].price <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortProducts(Product arr[], int low, int high) {
    if (low >= high) return;
    int pivotIndex = partitionProducts(arr, low, high);
    quickSortProducts(arr, low, pivotIndex - 1);
    quickSortProducts(arr, pivotIndex + 1, high);
}

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product products[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name of product " << i + 1 << ": ";
        cin >> products[i].name;
        cout << "Enter description of product " << i + 1 << ": ";
        cin.ignore();
        getline(cin, products[i].description);
        cout << "Enter price of product " << i + 1 << ": ";
        cin >> products[i].price;
        cout << "Enter availability (1 for available, 0 for not available): ";
        cin >> products[i].available;
    }

    quickSortProducts(products, 0, n - 1);

    cout << "\nProducts sorted by price (ascending):\n";
    for (int i = 0; i < n; i++)
        cout << products[i].name << " - " << products[i].price << endl;

    return 0;
