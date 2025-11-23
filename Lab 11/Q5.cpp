#include <iostream>
#include <string>
using namespace std;

class StudentHashTable {
    int size = 15;
    int roll[15];
    string name[15];

public:
    StudentHashTable() {
        for (int i = 0; i < size; i++) {
            roll[i] = -1;
            name[i] = "";
        }
    }

    void InsertRecord(int r, const string& n) {
        int idx = r % size;
        int attempt = 0;

        while (attempt < size) {
            int newIdx = (idx + attempt * attempt) % size;
            if (roll[newIdx] == -1) {
                roll[newIdx] = r;
                name[newIdx] = n;
                return;
            }
            attempt++;
        }

        cout << "Hash table full" << endl;
    }

    void SearchRecord(int r) {
        int idx = r % size;
        int attempt = 0;

        while (attempt < size) {
            int newIdx = (idx + attempt * attempt) % size;
            if (roll[newIdx] == r) {
                cout << name[newIdx] << endl;
                return;
            }
            if (roll[newIdx] == -1) break;
            attempt++;
        }

        cout << "Record not found" << endl;
    }
};

int main() {
    StudentHashTable ht;

    ht.InsertRecord(10, "Ali");
    ht.InsertRecord(25, "Sara");
    ht.InsertRecord(40, "John");

    ht.SearchRecord(25);
    ht.SearchRecord(99);
}
