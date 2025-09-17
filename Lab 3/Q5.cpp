#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* addNode(Node* head, char val) {
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

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = reverseList(slow->next);
    Node* copySecond = secondHalf;

    Node* firstHalf = head;
    bool palindrome = true;
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    slow->next = reverseList(copySecond);

    return palindrome;
}

int main() {
    Node* head = nullptr;
    string input = "BORROWORROB";

    for (char c : input) {
        head = addNode(head, c);
    }

    if (isPalindrome(head))
        cout << "Linked List is a Palindrome\n";
    else
        cout << "Linked List is not a Palindrome\n";

    return 0;
}
