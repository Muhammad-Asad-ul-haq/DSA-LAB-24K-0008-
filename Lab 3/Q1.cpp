#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* addNode(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtPos(Node* head, int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }
    if (temp) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node* deleteNode(Node* head, int value) {
    if (!head) return nullptr;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    return head;
}

int main() {
    int arr[] = {3, 1, 2, 5, 8};
    Node* head = nullptr;
   
    for (int i = 0; i < 5; i++) {
        head = addNode(head, arr[i]);
    }

    printList(head);

    head = addNode(head, 9);
    head = insertAtPos(head, 11, 3);
    head = insertAtPos(head, 4, 1);

    printList(head);

    head = deleteNode(head, 1);
    head = deleteNode(head, 2);
    head = deleteNode(head, 5);

    printList(head);

    return 0;
}
