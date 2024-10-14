// Create a C++ class named &quot;Exam&quot; designed to manage student exam records, complete with a
// shallow copy implementation? Define attributes such as student name, exam date, and score within the
// class, and include methods to set these attributes and display exam details. As part of this exercise,
// intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward,
// create an instance of the &quot;Exam&quot; class, generate a shallow copy, and observe any resulting issues?

#include <iostream>
using namespace std;

class Exam {
    private:
        string studentName;
        string examDate;
        int examScore;
    public:
    Exam() {

    }
    void getData(){
        cout << "Enter the Student name: ";
        cin >> studentName;
        cout << "Enter the Exam date: ";
        cin >> examDate;
        cout << "Enter the Exam score: ";
        cin >> examScore;
    }
    void display() {
        cout << "Student name: " << studentName << endl;
        cout << "Exam date: " << examDate << endl;
        cout << "Exam score: " << examScore << endl;
    }
};

int main() {
    Exam e1;
    e1.getData();
    Exam e2 = e1;
    e1.display();
    e2.display();
    return 0;
}