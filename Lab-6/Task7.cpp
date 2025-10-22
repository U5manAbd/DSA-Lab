#include <iostream>
using namespace std;

#define MAX 10

class LibraryQueue {
private:
    int front, rear;
    string patrons[MAX];

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full! No more patrons can join.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        patrons[rear] = name;
        cout << name << " has entered the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No patrons in the queue!\n";
            return;
        }

        cout << patrons[front] << " has completed their transaction and left.\n";
        front++;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "The queue is currently empty.\n";
            return;
        }

        cout << "\nCurrent Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << patrons[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    LibraryQueue queue;
    int choice;
    string name;

    cout << "===== Library Queue Simulation =====\n";

    do {
        cout << "\n1. Add Patron to Queue\n";
        cout << "2. Complete Transaction (Dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patron name: ";
            cin >> name;
            queue.enqueue(name);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.displayQueue();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
