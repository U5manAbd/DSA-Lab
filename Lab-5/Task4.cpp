#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool search(Node* head, int value) {
    if (head == nullptr) {
        return false;
    }
    if (head->data == value) {
        return true;
    }
    return search(head->next, value);
}

void insertEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

int main() {
    Node* head = nullptr;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    int valueToFind = 20;
    if (search(head, valueToFind)) {
        cout << valueToFind << " found in the list." << endl;
    } else {
        cout << valueToFind << " not found in the list." << endl;
    }
    return 0;
}