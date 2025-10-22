#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    string items[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(string task) {
        if (isFull()) {
            cout << "Error: To-do list is full\n";
            return;
        }
        top++;
        items[top] = task;
        cout << "Added task: " << task << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "To-do list is empty\n";
            return;
        }
        cout << "Removed task: " << items[top--] << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "To-do list is empty\n";
        } else {
            cout << "Next task: " << items[top] << endl;
        }
    }
};

int main() {
    Stack todoList;

    todoList.push("Do DSA Lab Tasks");
    todoList.push("Complete COAL Project");
    todoList.push("Prepare for MID II");

    todoList.peek();
    todoList.pop();
    todoList.pop();
    todoList.peek();
}
