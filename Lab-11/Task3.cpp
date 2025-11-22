#include <iostream>
#include <string>
using namespace std;

class Hash {
private:
    static const int TABLE_SIZE = 10;

    struct Node {
        string key, value;
        Node* next;
        Node(string k, string v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    Node* table[TABLE_SIZE];

    int hashFunction(const string &key) {
        int sum = 0;
        for (char c : key) sum += int(c);
        return sum % TABLE_SIZE;
    }

public:
    Hash() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    void insert(const string &key, const string &value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void delete_key(const string &key) {
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
                cout << "Key '" << key << "' deleted!\n";
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Key not found!\n";
    }

    string search(const string &key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }

        return "NOT_FOUND";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Hash h;

    h.insert("A", "Apple");
    h.insert("B", "Ball");
    h.insert("C", "Cat");

    cout << "Search B: " << h.search("B") << endl;

    h.delete_key("B");

    h.display();

    return 0;
}
