#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* addNode(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* rearrangeEvenOdd(Node* head) {
    Node *evenHead = nullptr, *evenTail = nullptr;
    Node *oddHead = nullptr, *oddTail = nullptr;

    while (head) {
        if (head->data % 2 == 0) {
            if (!evenHead) evenHead = evenTail = new Node{head->data, nullptr};
            else {
                evenTail->next = new Node{head->data, nullptr};
                evenTail = evenTail->next;
            }
        } else {
            if (!oddHead) oddHead = oddTail = new Node{head->data, nullptr};
            else {
                oddTail->next = new Node{head->data, nullptr};
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }

    if (!evenHead) return oddHead;
    if (!oddHead) return evenHead;

    evenTail->next = oddHead;
    return evenHead;
}

int main() {
    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    Node* head = nullptr;
    for (int i = 0; i < 10; i++) {
        head = addNode(head, arr[i]);
    }

    cout << "Original List: ";
    printList(head);

    head = rearrangeEvenOdd(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
