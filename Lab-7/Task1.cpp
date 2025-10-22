#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

void addNode(Node** head, string name, int score) {
    Node* newNode = new Node{name, score, nullptr};
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

int getMax(Node* head) {
    int mx = 0;
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        if (temp->score > mx)
            mx = temp->score;
    return mx;
}

void countSort(Node** head, int exp) {
    Node* output = nullptr;
    Node* countArr[10] = {nullptr};
    Node* countTail[10] = {nullptr};

    for (Node* temp = *head; temp != nullptr; temp = temp->next) {
        int digit = (temp->score / exp) % 10;
        Node* newNode = new Node{temp->name, temp->score, nullptr};
        if (countArr[digit] == nullptr)
            countArr[digit] = countTail[digit] = newNode;
        else {
            countTail[digit]->next = newNode;
            countTail[digit] = newNode;
        }
    }

    Node* tail = nullptr;
    for (int i = 0; i < 10; i++) {
        if (countArr[i] == nullptr) continue;
        if (output == nullptr) {
            output = countArr[i];
            tail = countTail[i];
        } else {
            tail->next = countArr[i];
            tail = countTail[i];
        }
    }

    *head = output;
}

void radixSort(Node** head) {
    int m = getMax(*head);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(head, exp);
}

void display(Node* head) {
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        cout << temp->name << " " << temp->score << endl;
}

int listLength(Node* head) {
    int len = 0;
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        len++;
    return len;
}

Node* binarySearch(Node* head, string name, int score) {
    int n = listLength(head);
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        Node* temp = head;
        for (int i = 0; i < mid; i++)
            temp = temp->next;

        if (temp->score == score && temp->name == name)
            return temp;
        else if (temp->score < score)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return nullptr;
}

void deleteRecord(Node** head, string name, int score) {
    Node* temp = *head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->name == name && temp->score == score) {
            if (prev == nullptr)
                *head = temp->next;
            else
                prev->next = temp->next;
            delete temp;
            cout << "\nRecord deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "\nRecord not found. Nothing deleted.\n";
}

int main() {
    Node* head = nullptr;

    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);

    cout << "\nOriginal List:\n";
    display(head);

    radixSort(&head);
    cout << "\nSorted List:\n";
    display(head);

    string searchName;
    int searchScore;
    cout << "\nEnter name and score to delete: ";
    cin >> searchName >> searchScore;

    Node* found = binarySearch(head, searchName, searchScore);
    if (found != nullptr)
        deleteRecord(&head, searchName, searchScore);
    else
        cout << "\nRecord not found. Nothing deleted.\n";

    cout << "\nUpdated List:\n";
    display(head);

    return 0;
}
