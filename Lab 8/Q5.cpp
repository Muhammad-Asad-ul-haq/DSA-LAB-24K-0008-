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

bool isBSTUtil(Node* node, int minVal, int maxVal) {
    if (!node) return true;
    if (node->data <= minVal || node->data >= maxVal)
        return false;
    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    // First Tree
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    root1->right->right = new Node(5);

    // Second Tree
    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(20);
    root2->left->right = new Node(9);
    root2->right->right = new Node(25);

    cout << "Tree 1 is " << (isBST(root1) ? "a BST" : "not a BST") << endl;
    cout << "Tree 2 is " << (isBST(root2) ? "a BST" : "not a BST") << endl;

    return 0;
}
