#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Hash {
    int size;
    vector<list<pair<string,string>>> table;

    int hashFunc(const string& s) {
        int sum = 0;
        for (char c : s) sum += c;
        return sum % size;
    }

public:
    Hash(int s = 10) : size(s), table(s) {}

    void insertRecord(const string& key, const string& value) {
        int idx = hashFunc(key);
        table[idx].push_back({key, value});
    }

    void deleteRecord(const string& key) {
        int idx = hashFunc(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
            if (it->first == key) {
                table[idx].erase(it);
                cout << "deleted: " << key << endl;
                return;
            }
        }
        cout << "not found" << endl;
    }

    void searchRecord(const string& key) {
        int idx = hashFunc(key);
        for (auto& p : table[idx]) {
            if (p.first == key) {
                cout << "found: " << p.first << " -> " << p.second << endl;
                return;
            }
        }
        cout << "not found" << endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (auto& p : table[i]) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Hash h(10);

    h.insertRecord("A", "aaaaa");
    h.insertRecord("B", "bbbbb");
    h.insertRecord("C", "ccccc");
    h.insertRecord("A", "zzzzz");

    h.searchRecord("C");
    h.deleteRecord("A");
    h.display();
}
