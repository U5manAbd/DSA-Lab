#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort(Node* head) {
    if (head == NULL) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;
    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void mergeAlternate(Node* head1, Node*& head2) {
    Node* curr1 = head1;
    Node* curr2 = head2;
    Node* next1;
    Node* next2;

    while (curr1 != NULL && curr2 != NULL) {
        next1 = curr1->next;
        next2 = curr2->next;

        curr1->next = curr2;
        curr2->next = next1;

        curr1 = next1;
        curr2 = next2;
    }
    head2 = curr2;
}

int main() {
    Node* head = NULL;
    insertEnd(head, 3);
    insertEnd(head, 1);
    insertEnd(head, 4);
    insertEnd(head, 2);
    insertEnd(head, 5);

    cout << "Original List: ";
    display(head);

    bubbleSort(head);
    cout << "Sorted List: ";
    display(head);

    Node* list1 = NULL;
    Node* list2 = NULL;

    insertEnd(list1, 1);
    insertEnd(list1, 2);
    insertEnd(list1, 3);

    insertEnd(list2, 100);
    insertEnd(list2, 200);
    insertEnd(list2, 300);
    insertEnd(list2, 400);

    cout << "List1 before merge: ";
    display(list1);
    cout << "List2 before merge: ";
    display(list2);

    mergeAlternate(list1, list2);

    cout << "List1 after merge alternate: ";
    display(list1);
    cout << "Remaining List2: ";
    display(list2);
}