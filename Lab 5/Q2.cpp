#include <iostream>
using namespace std;

class Student{
    int roll;
    string name;

    public:
    Student(int roll, string name) {
        this->name = name;
        this->roll = roll;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
    }
};

struct Node{
    Student std;
    Node *next;

    Node(Student s) : std(s), next(nullptr) {}
};

class LinkeLst{
    Node *head, *tail;
    public:
    

    LinkeLst() : head(nullptr), tail(nullptr) {}

        void insert(Student s) {
        Node* new_node = new Node(s);

        if (head == nullptr) {
            head = tail = new_node;   
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void display() {
        Node *current = head;
        while (current->next != nullptr) {
            current->std.display();
            current= current->next;
        }
    }
};


int main() {
    Student s1(341, "Ahmed");
    Student s2(634, "Ali");
    Student s3(6327, "Ayan");

    LinkeLst l1;
    l1.insert(s1);
    l1.insert(s2);
    l1.insert(s3);

    l1.display();
}
