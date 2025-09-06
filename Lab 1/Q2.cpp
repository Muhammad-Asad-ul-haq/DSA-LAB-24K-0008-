#include <iostream>
using namespace std;

class Exam {
public:
    string* name; 
    string* date;    
    int score;

    
    Exam(string name, string date, int score) {
        this->name = new string(name); 
        this->date = new string(date);    
        this->score = score;
    }

    
    ~Exam() {
        delete name;
        delete date;
    }

   
    void display() {
        cout << "Student Name: " << *name;
        cout<<"\nExam Date: " << *date;
        cout<<"\nScore: " << score << endl;
    }
};

int main() {
    
    Exam exam1("Lewandowski", "4 October 2025", 78);
    cout << "Exam 1 details:\n";
    exam1.display();

    cout << "-------------------\n";

  
    Exam exam2(exam1);
    cout << "Exam 2 details (copied from Exam1):\n";
    exam2.display();

}
