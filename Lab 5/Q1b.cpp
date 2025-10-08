#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev, *next;
};

Node* head = NULL;

void display() {
    for (Node* t = head; t; t = t->next) cout << t->data << " ";
    cout << endl;
}

void insertAt(int data, int pos) {
    Node* n = new Node{data, NULL, NULL};
    if (pos == 1) {
        n->next = head;
        if (head) head->prev = n;
        head = n;
        return;
    }
    Node* t = head;
    for (int i = 1; t && i < pos - 1; i++) t = t->next;
    if (!t) return;
    n->next = t->next;
    if (t->next) t->next->prev = n;
    t->next = n; n->prev = t;
}

void deleteAt(int pos) {
    if (!head) return;
    Node* t = head;
    if (pos == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        delete t; return;
    }
    for (int i = 1; t && i < pos; i++) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

int main() {
    insertAt(10,1);
    insertAt(20,2);
    insertAt(30,3);
    insertAt(15,2);
    cout<<"After insertion: "; display();
    deleteAt(3);
    cout<<"After deletion: "; display();
}
