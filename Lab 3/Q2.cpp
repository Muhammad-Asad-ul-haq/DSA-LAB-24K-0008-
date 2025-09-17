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

Node* rotateList(Node* head, int n) {
    if (!head || n <= 0) return head;

    Node* temp = head;
    int length = 1;
    while (temp->next) {
        length++;
        temp = temp->next;
    }

    n = n % length;
    if (n == 0) return head;

    temp->next = head;
    Node* newHead = head;
    for (int i = 1; i < length - n; i++) {
        newHead = newHead->next;
    }

    Node* resultHead = newHead->next;
    newHead->next = nullptr;

    return resultHead;
}

int main() {
    int arr[] = {5, 3, 1, 8, 6, 4, 2};
    Node* head = nullptr;
    for (int i = 0; i < 7; i++) {
        head = addNode(head, arr[i]);
    }

    cout << "Original list: ";
    printList(head);

    int n;
    cout << "Enter the number of elements to move to the end: ";
    cin >> n;

    head = rotateList(head, n);

    cout << "After rotation: ";
    printList(head);

    return 0;
}
