#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

void addNode(Node** head, string name, int score) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->score = score;
    newNode->next = *head;
    *head = newNode;
}

int getMax(Node* head) {
    int max = 0;
    while (head) {
        if (head->score > max)
            max = head->score;
        head = head->next;
    }
    return max;
}

int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNodeAt(Node* head, int index) {
    int i = 0;
    while (head && i < index) {
        head = head->next;
        i++;
    }
    return head;
}

void countingSort(Node** head, int exp) {
    Node* output[10000];
    int count[10];
    for (int i = 0; i < 10; i++)
        count[i] = 0;

    int n = getLength(*head);
    Node* temp = *head;
    Node* arr[10000];
    int i = 0;
    while (temp) {
        arr[i++] = temp;
        temp = temp->next;
    }

    for (i = 0; i < n; i++)
        count[(arr[i]->score / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        int idx = (arr[i]->score / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    for (i = 0; i < n - 1; i++)
        output[i]->next = output[i + 1];
    if (n > 0)
        output[n - 1]->next = NULL;
    *head = output[0];
}

void radixSort(Node** head) {
    int maxVal = getMax(*head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(head, exp);
}

void display(Node* head) {
    while (head) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int binarySearch(Node* head, string name, int score) {
    int low = 0;
    int high = getLength(head) - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        Node* midNode = getNodeAt(head, mid);
        if (midNode->score == score && midNode->name == name)
            return mid;
        else if (midNode->score < score)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void deleteRecord(Node** head, string name, int score) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp) {
        if (temp->name == name && temp->score == score) {
            if (prev)
                prev->next = temp->next;
            else
                *head = temp->next;
            delete temp;
            cout << "Record deleted successfully" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Record not found" << endl;
}

int main() {
    Node* head = NULL;

    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);

    cout << "Original List:" << endl;
    display(head);

    radixSort(&head);
    cout << "\nSorted List:" << endl;
    display(head);

    string name;
    int score;
    cout << "\nEnter name and score to delete: ";
    cin >> name >> score;

    int pos = binarySearch(head, name, score);
    if (pos != -1)
        deleteRecord(&head, name, score);
    else
        cout << "Record not found" << endl;

    cout << "\nUpdated List:" << endl;
    display(head);

    return 0;
}

