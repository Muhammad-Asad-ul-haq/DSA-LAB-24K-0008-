#include <iostream>
#include <vector>
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

    void inorder(Node* node, vector<int>& values) {
        if (!node) return;
        inorder(node->left, values);
        values.push_back(node->data);
        inorder(node->right, values);
    }

    double findMedian() {
        vector<int> values;
        inorder(root, values);

        int n = values.size();
        if (n == 0) return 0.0;

        if (n % 2 != 0)
            return values[n / 2];
        else
            return (values[(n / 2) - 1] + values[n / 2]) / 2.0;
    }
};

int main() {
    BST tree;
    tree.insertValue(20);
    tree.insertValue(10);
    tree.insertValue(30);
    tree.insertValue(5);
    tree.insertValue(15);
    tree.insertValue(25);
    tree.insertValue(35);

    cout << "Median of BST: " << tree.findMedian() << endl;

    return 0;
}
