#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = tail = new_node;   
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void display_reverse(Node* node) {
        if (node == nullptr) {
            return;
        }
        display_reverse(node->next);
        cout << node->data << " ";
    }
};

int main() {
    LinkedList l1;
    l1.insert(12);
    l1.insert(10);
    l1.insert(9);
    l1.insert(77);
    l1.insert(0);

    cout << "Linked List in Reverse: ";
    l1.display_reverse(l1.head);   
    cout << endl;

    return 0;
}
