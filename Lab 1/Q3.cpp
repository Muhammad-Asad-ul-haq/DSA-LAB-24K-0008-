#include <iostream>
using namespace std;

class Box {
public:
    int* value;

    Box(int value) {
        this->value = new int;   
        *this->value = value;        
    }

    ~Box() {
        delete value;
    }

    Box(Box& variation) {
        this->value = new int;
        *this->value = *variation.value;
    }

    Box& operator=(Box& variation) {
        if (this != &variation) {
            delete this->value;
            this->value = new int;
            *this->value = *variation.value;
        }
        return *this;
    }

    void show() {
        cout << *this->value << endl;
    }
};

int main() {
    Box box1(10);
    cout << "box 1 = "; box1.show();

    Box box2(box1);
    cout << "box 2 COPIED = "; box2.show();

    *box2.value = 41;
    
    cout << "\nAfter changing the value of box 2:\n" << endl;
    cout << "box 1 = "; box1.show();
    cout << "box 2 = "; box2.show();

    Box box3(45);
    cout << "box 3 = "; box3.show();

    box3 = box1;
    cout << "\nbox 3 After assigned = "; box3.show();

    return 0;
}
