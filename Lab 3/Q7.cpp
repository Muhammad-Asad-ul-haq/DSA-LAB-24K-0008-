#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* tail, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!tail) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return newNode;
}

Node* insertBeginning(Node* tail, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!tail) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}

Node* insertAtPosition(Node* tail, int val, int pos) {
    if (!tail && pos > 1) {
        cout << "Position out of range\n";
        return tail;
    }
    if (pos == 1) return insertBeginning(tail, val);

    Node* temp = tail->next;
    int count = 1;
    while (count < pos - 1 && temp != tail) {
        temp = temp->next;
        count++;
    }
    if (count != pos - 1) {
        cout << "Position out of range\n";
        return tail;
    }
    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;
    if (temp == tail) return newNode;
    return tail;
}

Node* deleteNode(Node* tail, int val) {
    if (!tail) return nullptr;
    Node* curr = tail->next;
    Node* prev = tail;
    do {
        if (curr->data == val) {
            if (curr == prev) {
                delete curr;
                return nullptr;
            }
            prev->next = curr->next;
            if (curr == tail) tail = prev;
            delete curr;
            return tail;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
    cout << val << " not found\n";
    return tail;
}

void printList(Node* tail) {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "\n";
}

int main() {
    Node* tail = nullptr;

    tail = insertEnd(tail, 10);
    tail = insertEnd(tail, 20);
    tail = insertEnd(tail, 30);
    printList(tail);

    tail = insertBeginning(tail, 5);
    printList(tail);

    tail = insertAtPosition(tail, 15, 3);
    printList(tail);

    tail = deleteNode(tail, 20);
    printList(tail);

    tail = deleteNode(tail, 100);
    printList(tail);

    return 0;
}
