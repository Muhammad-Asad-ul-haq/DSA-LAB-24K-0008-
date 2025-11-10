
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int v) {
        value = v;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    Node* search(Node* node, int value) {
        if (!node || node->value == value)
            return node;
        if (value < node->value)
            return search(node->left, value);
        return search(node->right, value);
    }

    bool exists(int value) {
        return search(root, value) != nullptr;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int initialValues[] = {20, 10, 30, 5, 15, 25, 35};
    for (int v : initialValues)
        tree.insert(v);

    cout << "Current Tree (Inorder): ";
    tree.display();

    int value;
    cout << "\nEnter a value to search: ";
    cin >> value;

    if (tree.exists(value))
        cout << "Value " << value << " already exists in the tree.\n";
    else {
        cout << "Value not found. Inserting " << value << "...\n";
        tree.insert(value);
        cout << "Updated Tree (Inorder): ";
        tree.display();
    }

    return 0;
}
