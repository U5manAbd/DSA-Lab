#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    bool occupied;

    Student() {
        roll = -1;
        name = "";
        occupied = false;
    }
};

class StudentHashTable {
private:
    static const int TABLE_SIZE = 15;
    Student table[TABLE_SIZE];

    int hashFunction(int roll) {
        return roll % TABLE_SIZE;
    }

public:

    void InsertRecord(int roll, string name) {
        int index = hashFunction(roll);

        for (int attempt = 0; attempt < TABLE_SIZE; attempt++) {

            int newIndex = (index + attempt * attempt) % TABLE_SIZE;

            if (!table[newIndex].occupied) {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].occupied = true;

                cout << "Inserted at index " << newIndex << endl;
                return;
            }
        }
        cout << "Hash table full! Cannot insert.\n";
    }

    void SearchRecord(int roll) {
        int index = hashFunction(roll);

        for (int attempt = 0; attempt < TABLE_SIZE; attempt++) {

            int newIndex = (index + attempt * attempt) % TABLE_SIZE;

            if (table[newIndex].occupied && table[newIndex].roll == roll) {
                cout << "Record found: " << table[newIndex].name << endl;
                return;
            }
        }

        cout << "Record not found\n";
    }

    void Display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].occupied)
                cout << i << ": (" << table[i].roll << ", " << table[i].name << ")\n";
            else
                cout << i << ": ---\n";
        }
    }
};


int main() {
    StudentHashTable t;

    t.InsertRecord(100, "Ali");
    t.InsertRecord(55, "Ahmed");
    t.InsertRecord(77, "Zara");
    t.InsertRecord(130, "Usman");

    t.SearchRecord(77);
    t.SearchRecord(200);

    cout << "\nHash Table:\n";
    t.Display();

    return 0;
}
