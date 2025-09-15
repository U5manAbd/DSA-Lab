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

   int find_length(Node *head,int sum){
    if(head->next==nullptr){
        return 0;
    }
    return 1+ find_length(head->next,sum);
   }
};

int main (){
    LinkedList l1;
    l1.insertAtEnd(10);
    l1.insertAtEnd(40);
    l1.insertAtEnd(30);
    l1.insertAtEnd(5);
    Node *head=l1.return_head();
    int total=l1.find_length(head,0);
    cout<<total<<endl;
}