#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* addNode(Node* head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* modifyList(Node* head) {
    if (!head || !head->next) return head;

    Node* altHead = nullptr;
    Node* altTail = nullptr;
    Node* curr = head;

    while (curr && curr->next) {
        Node* alt = curr->next;
        curr->next = alt->next;
        alt->next = nullptr;
        if (!altHead) altHead = altTail = alt;
        else {
            altTail->next = alt;
            altTail = alt;
        }
        curr = curr->next;
    }

    altHead = reverseList(altHead);

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = altHead;

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    for (int v : arr) head = addNode(head, v);

    head = modifyList(head);

    printList(head);

    return 0;
}
