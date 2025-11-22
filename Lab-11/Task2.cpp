#include <iostream>
#include <string>
using namespace std;

class Dictionary {
private:
    static const int SIZE = 100;

    struct Node {
        string key, value;
        Node* next;
        Node(string k, string v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    Node* table[SIZE];

    int hashFunction(const string &key) {
        int sum = 0;
        for (char c : key) sum += int(c);
        return sum % SIZE;
    }

public:
    Dictionary() {
        for (int i = 0; i < SIZE; i++)
            table[i] = nullptr;
    }

    void Add_Record(const string &key, const string &value) {
        int index = hashFunction(key);

        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void Word_Search(const string &key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->key == key) {
                cout << "search key " << key << ": " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Error! Word '" << key << "' not found!" << endl;
    }

    void Delete_Record(const string &key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr)
                    table[index] = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Error! Key '" << key << "' not found!" << endl;
    }

    void Print_Dictionary() {
        for (int i = 0; i < SIZE; i++) {
            Node* temp = table[i];
            if (temp != nullptr) {
                cout << "index " << i << ": ";
                while (temp != nullptr) {
                    cout << "(" << temp->key << ", " << temp->value << ") ";
                    temp = temp->next;
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
    d.Add_Record("EF", "SE");

    d.Word_Search("AB");
    d.Delete_Record("EF");
    d.Print_Dictionary();

    return 0;
}