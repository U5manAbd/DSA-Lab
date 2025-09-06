#include<iostream>
using namespace std;

struct Item
{
    int val;
    Item* nxt;
};

void show(Item* tail)
{
    if(!tail)
    {
        cout<<"Empty"<<endl;
        return;
    }
    Item* p=tail->nxt;
    do
    {
        cout<<p->val<<" ";
        p=p->nxt;
    }
    while(p!=tail->nxt);
    cout<<endl;
}

void addLast(Item*& tail,int v)
{
    Item* n=new Item{v,NULL};
    if(!tail)
    {
        tail=n;
        tail->nxt=tail;
        return;
    }
    n->nxt=tail->nxt;
    tail->nxt=n;
    tail=n;
}

void addFirst(Item*& tail,int v)
{
    Item* n=new Item{v,NULL};
    if(!tail)
    {
        tail=n;
        tail->nxt=tail;
        return;
    }
    n->nxt=tail->nxt;
    tail->nxt=n;
}

void addPos(Item*& tail,int v,int pos)
{
    if(!tail) return;
    Item* p=tail->nxt;
    for(int i=1;i<pos-1 && p!=tail;i++)
    {
        p=p->nxt;
    }
    Item* n=new Item{v,p->nxt};
    p->nxt=n;
    if(p==tail) tail=n;
}

void removeVal(Item*& tail,int v)
{
    if(!tail) return;
    Item* cur=tail->nxt;
    Item* prev=tail;
    do
    {
        if(cur->val==v)
        {
            if(cur==tail && cur==tail->nxt)
            {
                delete cur;
                tail=NULL;
                return;
            }
            prev->nxt=cur->nxt;
            if(cur==tail) tail=prev;
            delete cur;
            return;
        }
        prev=cur;
        cur=cur->nxt;
    }
    while(cur!=tail->nxt);
}

int main()
{
    Item* tail=NULL;
    addLast(tail,1);
    addLast(tail,2);
    addLast(tail,3);
    show(tail);
    addFirst(tail,0);
    show(tail);
    addPos(tail,99,3);
    show(tail);
    removeVal(tail,2);
    show(tail);
}
