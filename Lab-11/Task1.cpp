#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    static const int BUCKETS = 10;

    struct Node {
        string key, value;
        Node* next;
        Node(string k, string v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    Node* table[BUCKETS];

    int hashFunction(const string &key) {
        int sum = 0;
        for (char c : key) sum += int(c);
        return sum % BUCKETS;
    }

public:
    HashTable() {
        for (int i = 0; i < BUCKETS; i++)
            table[i] = nullptr;
    }

    void insert(const string &key, const string &value) {
        int index = hashFunction(key);

        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void display() {
        for (int i = 0; i < BUCKETS; i++) {
            cout << "Bucket " << i << ": ";
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
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.display();

    return 0;
}