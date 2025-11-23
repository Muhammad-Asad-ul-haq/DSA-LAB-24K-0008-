#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string key, value;
    Node* next;
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
    int size;
    vector<Node*> table;

    int hashFunc(const string& s) {
        int sum = 0;
        for (char c : s) sum += c;
        return sum % size;
    }

public:
    HashTable(int s = 10) : size(s), table(s, nullptr) {}

    void insert(const string& key, const string& value) {
        int idx = hashFunc(key);
        Node* n = new Node(key, value);
        n->next = table[idx];
        table[idx] = n;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* t = table[i];
            while (t) {
                cout << "(" << t->key << "," << t->value << ") ";
                t = t->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myhash;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    myhash.print();
}
