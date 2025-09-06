#include<iostream>
#include<string>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

void print(Node* h)
{
    while(h)
    {
        cout << h->data;
        if(h->next) 
            cout << "->";
        h = h->next;
    }
    cout << "->NULL" << endl;
}

bool isPalindrome(Node* head)
{
    if(!head || !head->next) 
        return true;

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* prev = NULL;
    Node* cur = slow;
    Node* nxt = NULL;

    while(cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    Node* left = head;
    Node* right = prev;

    while(right)
    {
        if(left->data != right->data) 
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

int main()
{
    char arr[] = {'B','O','R','R','O','B'};
    Node* head = new Node{arr[0],NULL};
    Node* t = head;

    for(int i=1;i<6;i++)
    {
        t->next = new Node{arr[i],NULL};
        t = t->next;
    }

    print(head);
    if(isPalindrome(head)) 
        cout << "Linked List  Palindrome\n";
    else 
        cout << "Linked List is NotPalindrome\n";
}
