#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFront(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
}

void deleteLast(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
}

void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL || pos <= 0) return;
    if (pos == 1) {
        deleteFront(head);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) return;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    delete temp;
}

Node* reverseRecursive(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head->prev;
    head->prev = head->next;
    head->next = temp;
    if (head->prev == NULL) return head;
    return reverseRecursive(head->prev);
}

int main() {
    Node* head = NULL;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "Original List: ";
    display(head);

    deleteFront(head);
    cout << "After deleting front: ";
    display(head);

    deleteLast(head);
    cout << "After deleting last: ";
    display(head);

    deleteAtPosition(head, 2);
    cout << "After deleting at position 2: ";
    display(head);

    head = reverseRecursive(head);
    cout << "Reversed List: ";
    display(head);
}