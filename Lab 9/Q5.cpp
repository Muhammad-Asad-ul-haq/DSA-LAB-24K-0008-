#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int h(Node* n) { return n ? n->height : 0; }
int bal(Node* n) { return h(n->left) - h(n->right); }

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}

Node* insertNode(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key) node->left = insertNode(node->left, key);
    else if (key > node->key) node->right = insertNode(node->right, key);

    node->height = 1 + max(h(node->left), h(node->right));
    int b = bal(node);

    if (b > 1 && key < node->left->key) return rightRotate(node);
    if (b < -1 && key > node->right->key) return leftRotate(node);
    if (b > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (b < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->key);
    inorder(root->right, v);
}

int main() {
    Node* root = NULL;
    int arr[] = {10,5,15,3,7,12};
    for (int x : arr) root = insertNode(root, x);

    vector<int> v;
    inorder(root, v);

    int k = 3;
    int kthSmall = v[k-1];
    int kthLarge = v[v.size()-k];

    int leftHeight = h(root->left);
    int rightHeight = h(root->right);

    cout << "Kth Smallest: " << kthSmall << endl;
    cout << "Kth Largest: " << kthLarge << endl;
    cout << "Left Height: " << leftHeight << endl;
    cout << "Right Height: " << rightHeight << endl;

    return 0;
}
