#include <iostream>
using namespace std;

struct Node {
    string url;
    Node* next;
};

class Stack {
private:
    string data[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string url) {
        top++;
        data[top] = url;
    }

    string pop() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return " ";
        }
        return data[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    string peek() {
        if (isEmpty()) return " ";
        return data[top];
    }
};

class BrowserHistory {
private:
    Node* head;
    Stack history;

public:
    BrowserHistory() {
        head = nullptr;
    }

    void visit(string url) {
        Node* newNode = new Node{url, head};
        head = newNode;
        history.push(url);
        cout << "Visited: " << url << endl;
    }

    void back(int times) {
        cout << "\nBacking " << times << " times" << endl;
        for (int i = 0; i < times; i++) {
            if (head == nullptr || history.isEmpty()) {
                cout << "No more history!\n";
                return;
            }
            string removedFromStack = history.pop();

            Node* temp = head;
            head = head->next;
            delete temp;

            
        }

        if (head)
            cout << "Current website: " << head->url << endl;
        else
            cout << "No pages left to view." << endl;
    }

    void showHistory() {
        cout << "\nCurrent Browsing History:" << endl;
        Node* temp = head;
        while (temp) {
            cout << temp->url << "  ";
            temp = temp->next;
        }
    }
};

int main() {
    BrowserHistory obj;

 obj.visit("Google");
 obj.visit("Facebook");
 obj.visit("Twitter");
 obj.visit("LinkedIn");
 obj.visit("Instagram");

 obj.showHistory();
 obj.back(2);
 obj.showHistory();
}
