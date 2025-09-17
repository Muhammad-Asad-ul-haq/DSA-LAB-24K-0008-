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

Node* deleteValue(Node* head, int val) {
    if (!head || head->data == val) {
        cout << "Cannot delete first node or empty list.\n";
        return head;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << val << " deleted from the list.\n";
    } else {
        cout << val << " not found in the list.\n";
    }
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
    int arr[] = {10, 20, 30, 40, 50};
    for (int v : arr) head = addNode(head, v);

    cout << "List before deletion: ";
    printList(head);

    int val;
    cout << "Enter value to delete (not first node): ";
    cin >> val;

    head = deleteValue(head, val);

    cout << "List after deletion: ";
    printList(head);

    return 0;
}
