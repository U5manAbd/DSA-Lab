#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot add customer " << value << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << "Customer " << value << " entered the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No customers to serve.\n";
            return;
        }
        cout << "Serving customer " << arr[front] << " and removing from queue.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Current queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    int n = 7;

    for (int i = 0; i < n; i++) {
        q.enqueue(customers[i]);
        q.display();
    }

    cout << "\n";
    while (!q.isEmpty()) {
        q.dequeue();
        q.display();
    }

    return 0;
}
