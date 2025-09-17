#include <iostream>
using namespace std;

struct Passenger {
    string name;
    Passenger* next;
};

Passenger* insertSorted(Passenger* head, string name) {
    Passenger* newNode = new Passenger{name, nullptr};
    if (!head || name < head->name) {
        newNode->next = head;
        return newNode;
    }
    Passenger* temp = head;
    while (temp->next && temp->next->name < name) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Passenger* cancel(Passenger* head, string name) {
    if (!head) return nullptr;
    if (head->name == name) {
        Passenger* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Passenger* temp = head;
    while (temp->next && temp->next->name != name) {
        temp = temp->next;
    }
    if (temp->next) {
        Passenger* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    return head;
}

bool check(Passenger* head, string name) {
    while (head) {
        if (head->name == name) return true;
        head = head->next;
    }
    return false;
}

void display(Passenger* head) {
    while (head) {
        cout << head->name << endl;
        head = head->next;
    }
}

int main() {
    Passenger* flight = nullptr;
    int choice;
    string name;

    do {
        cout << "\n1. Reserve\n2. Cancel\n3. Check\n4. Display\n5. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            flight = insertSorted(flight, name);
        } else if (choice == 2) {
            cout << "Enter name: ";
            cin >> name;
            flight = cancel(flight, name);
        } else if (choice == 3) {
            cout << "Enter name: ";
            cin >> name;
            cout << (check(flight, name) ? "Reserved" : "Not reserved") << endl;
        } else if (choice == 4) {
            display(flight);
        }
    } while (choice != 5);

    return 0;
}
