#include <iostream>
using namespace std;

class Exam {
private:
    string* name;
    string* date;
    int* score;
public:
    Exam() {
        name = new string;
        date = new string;
        score = new int;
    }

    void setExam(string n, string d, int s) {
        *name = n;
        *date = d;
        *score = s;
    }

    void displayExam() {
        cout << "Student Name: " << *name << endl;
        cout << "Exam Date: " << *date << endl;
        cout << "Score: " << *score << endl;
    }

    ~Exam() {
        delete name;
        delete date;
        delete score;
    }
};

int main() {
    Exam e1;
    e1.setExam("Usman", "25/08/2025", 94);
    e1.displayExam();

    Exam e2 = e1;
    cout << "Modifying e2!!!!" << endl;

    e2.setExam("Abdullah", "26/08/2025", 90);
    e1.displayExam();
}