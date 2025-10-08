#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool search(Node* head, int key) {
    if (head == nullptr) return false;
    if (head->data == key) return true;
    return search(head->next, key);
}

int main() {
    Node* head = new Node{5, new Node{10, new Node{15, nullptr}}};
    int key = 10;
    if (search(head, key))
        cout << "Found";
    else
        cout << "Not Found";
}
