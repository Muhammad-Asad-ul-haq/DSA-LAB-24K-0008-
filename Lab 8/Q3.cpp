#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int score;
    Student() {}
    Student(string n, int r, int s) {
        name = n;
        roll = r;
        score = s;
    }
};

class Node {
public:
    Student data;
    Node* left;
    Node* right;
    Node(Student s) {
        data = s;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, Student s) {
        if (!node) return new Node(s);
        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else
            node->right = insert(node->right, s);
        return node;
    }

    void insert(Student s) {
        root = insert(root, s);
    }

    Node* search(Node* node, string name) {
        if (!node || node->data.name == name)
            return node;
        if (name < node->data.name)
            return search(node->left, name);
        return search(node->right, name);
    }

    void searchByName(string name) {
        Node* result = search(root, name);
        if (result)
            cout << "Found: " << result->data.name << " | Roll: " << result->data.roll << " | Score: " << result->data.score << endl;
        else
            cout << "Student not found.\n";
    }

    Node* deleteByName(Node* node, string name) {
        if (!node) return node;
        if (name < node->data.name)
            node->left = deleteByName(node->left, name);
        else if (name > node->data.name)
            node->right = deleteByName(node->right, name);
        else {
            if (!node->left) return node->right;
            else if (!node->right) return node->left;
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteByName(node->right, temp->data.name);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    Node* maxScoreNode(Node* node, Node* currentMax) {
        if (!node) return currentMax;
        if (!currentMax || node->data.score > currentMax->data.score)
            currentMax = node;
        currentMax = maxScoreNode(node->left, currentMax);
        currentMax = maxScoreNode(node->right, currentMax);
        return currentMax;
    }

    void deleteLowScores(Node* node) {
        if (!node) return;
        deleteLowScores(node->left);
        deleteLowScores(node->right);
        if (node->data.score < 10)
            root = deleteByName(root, node->data.name);
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data.name << " (Roll: " << node->data.roll << ", Score: " << node->data.score << ")\n";
            inorder(node->right);
        }
    }

    void display() {
        inorder(root);
    }

    void showMaxScoreStudent() {
        Node* maxNode = maxScoreNode(root, nullptr);
        if (maxNode)
            cout << "Highest Score: " << maxNode->data.name << " | Roll: " << maxNode->data.roll << " | Score: " << maxNode->data.score << endl;
        else
            cout << "Tree is empty.\n";
    }
};

int main() {
    BST tree;
    Student students[10] = {
        {"Ali", 101, 12},
        {"Bilal", 102, 8},
        {"Zain", 103, 25},
        {"Omar", 104, 15},
        {"Sara", 105, 30},
        {"Nida", 106, 5},
        {"Hina", 107, 22},
        {"Rizwan", 108, 9},
        {"Usman", 109, 11},
        {"Fatima", 110, 18}
    };

    for (int i = 0; i < 10; i++)
        tree.insert(students[i]);

    cout << "All Students (Inorder):\n";
    tree.display();

    cout << "\nSearch for 'Sara':\n";
    tree.searchByName("Sara");

    cout << "\nDeleting students with score < 10...\n";
    tree.deleteLowScores(tree.root);

    cout << "\nAfter deletion:\n";
    tree.display();

    cout << "\nStudent with maximum score:\n";
    tree.showMaxScoreStudent();

    return 0;
}
