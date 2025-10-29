#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;

public:
    List() { head = nullptr; }

    void addFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getTail(Node* cur) {
        while (cur && cur->next)
            cur = cur->next;
        return cur;
    }

    Node* partitionList(Node* start, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node* prev = nullptr;
        Node* cur = start;
        Node* tail = pivot;

        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if (*newHead == nullptr)
                    *newHead = cur;
                prev = cur;
                cur = cur->next;
            } else {
                if (prev)
                    prev->next = cur->next;
                Node* temp = cur->next;
                cur->next = nullptr;
                tail->next = cur;
                tail = cur;
                cur = temp;
            }
        }

        if (*newHead == nullptr)
            *newHead = pivot;
        *newEnd = tail;
        return pivot;
    }

    Node* quickSortRecursive(Node* start, Node* end) {
        if (!start || start == end)
            return start;

        Node* newHead = nullptr;
        Node* newEnd = nullptr;
        Node* pivot = partitionList(start, end, &newHead, &newEnd);

        if (newHead != pivot) {
            Node* temp = newHead;
            while (temp->next != pivot)
                temp = temp->next;
            temp->next = nullptr;

            newHead = quickSortRecursive(newHead, temp);
            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRecursive(pivot->next, newEnd);
        return newHead;
    }

    void quickSort() {
        Node* end = getTail(head);
        head = quickSortRecursive(head, end);
    }
};

int main() {
    List list;
    list.addFront(3);
    list.addFront(5);
    list.addFront(1);
    list.addFront(9);
    list.addFront(8);
    list.addFront(7);
    list.addFront(10);

    cout << "Original List:\n";
    list.printList();

    list.quickSort();

    cout << "Sorted List:\n";
    list.printList();

    return 0;
}
