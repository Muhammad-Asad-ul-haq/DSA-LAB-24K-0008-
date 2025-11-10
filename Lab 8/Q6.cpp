#include <iostream>
using namespace std;

class Node {
public:
    int productID;
    int quantity;
    Node* left;
    Node* right;

    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = right = nullptr;
    }
};

class InventoryBST {
public:
    Node* root;

    InventoryBST() {
        root = nullptr;
    }

    Node* insert(Node* node, int id, int qty) {
        if (!node) return new Node(id, qty);

        if (id < node->productID)
            node->left = insert(node->left, id, qty);
        else if (id > node->productID)
            node->right = insert(node->right, id, qty);
        else
            node->quantity += qty; // Update quantity if product exists

        return node;
    }

    void insertProduct(int id, int qty) {
        root = insert(root, id, qty);
    }

    Node* search(Node* node, int id) {
        if (!node || node->productID == id)
            return node;
        if (id < node->productID)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    void searchProduct(int id) {
        Node* result = search(root, id);
        if (result)
            cout << "Product Found! ID: " << result->productID << ", Quantity: " << result->quantity << endl;
        else
            cout << "Product with ID " << id << " not found." << endl;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << "Product ID: " << node->productID << ", Quantity: " << node->quantity << endl;
        inorder(node->right);
    }

    void displayInventory() {
        cout << "\n--- Inventory List ---\n";
        inorder(root);
    }

    void findMaxQuantity(Node* node, int &maxQty, int &maxID) {
        if (!node) return;
        if (node->quantity > maxQty) {
            maxQty = node->quantity;
            maxID = node->productID;
        }
        findMaxQuantity(node->left, maxQty, maxID);
        findMaxQuantity(node->right, maxQty, maxID);
    }

    void showMaxQuantityProduct() {
        if (!root) {
            cout << "Inventory is empty.\n";
            return;
        }
        int maxQty = -1, maxID = -1;
        findMaxQuantity(root, maxQty, maxID);
        cout << "\nProduct with Highest Quantity:\nID: " << maxID << ", Quantity: " << maxQty << endl;
    }
};

int main() {
    InventoryBST inventory;

    inventory.insertProduct(101, 20);
    inventory.insertProduct(105, 15);
    inventory.insertProduct(103, 40);
    inventory.insertProduct(102, 25);
    inventory.insertProduct(104, 10);

    inventory.displayInventory();

    cout << "\nSearching for Product ID 103:\n";
    inventory.searchProduct(103);

    cout << "\nUpdating Product ID 105 (Adding 10 more units):\n";
    inventory.insertProduct(105, 10);

    inventory.displayInventory();

    inventory.showMaxQuantityProduct();

    return 0;
}
