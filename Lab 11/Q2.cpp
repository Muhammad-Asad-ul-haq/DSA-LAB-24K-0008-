#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string key, value;
    Node* next;
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

class Dictionary {
    vector<Node*> table;

    int hashFunc(const string& s) {
        int sum = 0;
        for (char c : s) sum += c;
        return sum % 100;
    }

public:
    Dictionary() : table(100, nullptr) {}

    void Add_Record(const string& key, const string& value) {
        int idx = hashFunc(key);
        Node* n = new Node(key, value);
        n->next = table[idx];
        table[idx] = n;
    }

    void Word_Search(const string& key) {
        int idx = hashFunc(key);
        Node* t = table[idx];
        while (t) {
            if (t->key == key) {
                cout << "search key " << key << ": " << t->value << endl;
                return;
            }
            t = t->next;
        }
        cout << "error: key not found" << endl;
    }

    void Delete_Record(const string& key) {
        int idx = hashFunc(key);
        Node* t = table[idx];
        Node* p = nullptr;
        while (t) {
            if (t->key == key) {
                if (p) p->next = t->next;
                else table[idx] = t->next;
                delete t;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
            p = t;
            t = t->next;
        }
        cout << "error: key not found" << endl;
    }

    void Print_Dictionary() {
        for (int i = 0; i < 100; i++) {
            if (table[i]) {
                cout << "index " << i << ": ";
                Node* t = table[i];
                while (t) {
                    cout << "(" << t->key << ", " << t->value << ") ";
                    t = t->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Dictionary d;

    d.Add_Record("AB", "FASTNU");
    d.Add_Record("CD", "CS");
    d.Add_Record("EF", "ENG");

    d.Word_Search("AB");
    d.Delete_Record("EF");
    d.Print_Dictionary();
}
