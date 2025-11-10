#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    Node* insertNode(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->value)
            node->left = insertNode(node->left, value);
        else
            node->right = insertNode(node->right, value);
        return node;
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void inorderTraversal(Node* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void preorderTraversal(Node* node) {
        if (node) {
            cout << node->value << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }

    void postorderTraversal(Node* node) {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->value << " ";
        }
    }

    Node* search(int value) {
        return searchNode(root, value);
    }

    Node* searchNode(Node* node, int value) {
        if (!node || node->value == value) return node;
        if (value < node->value) return searchNode(node->left, value);
        return searchNode(node->right, value);
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    Node* deleteNode(Node* node, int value) {
        if (!node) return node;
        if (value < node->value)
            node->left = deleteNode(node->left, value);
        else if (value > node->value)
            node->right = deleteNode(node->right, value);
        else {
            if (!node->left) return node->right;
            else if (!node->right) return node->left;
            Node* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }
};
