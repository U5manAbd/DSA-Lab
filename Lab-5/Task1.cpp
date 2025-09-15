#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

   void print_reverse(Node *temp){
    if(!temp){
        return;
    }
    print_reverse(temp->next);
    cout<<temp->data<<" ";
   }

   Node *return_head(){
    return head;
   }
};

int main() {
    LinkedList list;
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    Node *head=list.return_head();

    list.print_reverse(head);

    return 0;
}

