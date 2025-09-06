#include<iostream>
using namespace std;

struct Item
{
    int val;
    Item* back;
    Item* nxt;
};

struct DList
{
    Item* first;
    Item* last;
};

void push(DList& lst,int v)
{
    Item* n=new Item{v,NULL,NULL};
    if(!lst.first)
    {
        lst.first=n;
        lst.last=n;
        return;
    }
    lst.last->nxt=n;
    n->back=lst.last;
    lst.last=n;
}

void print(DList lst)
{
    Item* p=lst.first;
    while(p)
    {
        cout<<p->val<<" ";
        p=p->nxt;
    }
    cout<<endl;
}

DList merge(DList X,DList Y)
{
    if(!X.first) return Y;
    if(!Y.first) return X;
    X.last->nxt=Y.first;
    Y.first->back=X.last;
    X.last=Y.last;
    return X;
}

int main()
{
    DList A{NULL,NULL};
    DList B{NULL,NULL};
    push(A,10);
    push(A,20);
    push(A,30);
    push(B,40);
    push(B,50);
    push(B,60);
    print(A);
    print(B);
    DList C=merge(A,B);
    print(C);
}
