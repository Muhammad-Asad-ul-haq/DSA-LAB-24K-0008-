#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void insertValue(int val) {
        root = insert(root, val);
    }

    int countInRange(Node* node, int a, int b) {
        if (!node) return 0;
        if (node->data < a)
            return countInRange(node->right, a, b);
        else if (node->data > b)
            return countInRange(node->left, a, b);
        else
            return 1 + countInRange(node->left, a, b) + countInRange(node->right, a, b);
    }

    int countNodesInRange(int a, int b) {
        return countInRange(root, a, b);
    }
};

int main() {
    BST tree;
    tree.insertValue(10);
    tree.insertValue(5);
    tree.insertValue(50);
    tree.insertValue(1);
    tree.insertValue(40);
    tree.insertValue(100);

    int a = 5, b = 45;
    cout << "Number of nodes in range [" << a << ", " << b << "] = "
         << tree.countNodesInRange(a, b) << endl;

    return 0;
}
