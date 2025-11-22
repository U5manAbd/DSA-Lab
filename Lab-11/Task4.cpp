#include <iostream>
using namespace std;

struct Node {
    int sum;
    int a, b;
    Node* next;
};

class HashTable {
public:
    static const int SIZE = 1000;
    Node* table[SIZE];

    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = nullptr;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int sum, int a, int b) {
        int index = hashFunction(sum);

        Node* newNode = new Node{sum, a, b, table[index]};
        table[index] = newNode;
    }

    Node* search(int sum) {
        int index = hashFunction(sum);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->sum == sum)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

void findPairs(int arr[], int n) {
    HashTable ht;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];

            Node* existing = ht.search(sum);

            if (existing != nullptr) {
                int a = existing->a;
                int b = existing->b;
                int c = arr[i];
                int d = arr[j];

                if (a != c && a != d && b != c && b != d) {
                    cout << "(" << a << ", " << b << ") and ("
                         << c << ", " << d << ")" << endl;
                    return;
                }
            } else {
                ht.insert(sum, arr[i], arr[j]);
            }
        }
    }

    cout << "No pairs found" << endl;
}


int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};

    cout << "Test 1: ";
    findPairs(arr1, 7);

    cout << "Test 2: ";
    findPairs(arr2, 6);

    cout << "Test 3: ";
    findPairs(arr3, 7);

    return 0;
}
