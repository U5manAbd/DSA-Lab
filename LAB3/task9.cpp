#include<iostream>
using namespace std;

struct Item
{
    int val;
    Item* nxt;
};

void show(Item* h)
{
    while(h)
    {
        cout<<h->val<<" ";
        h=h->nxt;
    }
    cout<<endl;
}

void process(Item*& start)
{
    if(!start||!start->nxt) return;

    Item* a=start;
    Item* b=start->nxt;
    Item* bFirst=b;

    while(b&&b->nxt)
    {
        a->nxt=b->nxt;
        a=a->nxt;
        b->nxt=a->nxt;
        b=b->nxt;
    }

    Item* prev=NULL;
    Item* cur=bFirst;
    while(cur)
    {
        Item* nxt=cur->nxt;
        cur->nxt=prev;
        prev=cur;
        cur=nxt;
    }

    a->nxt=prev;
}

int main()
{
    int arr[]={10,4,9,1,3,5,9,4};
    Item* start=new Item{arr[0],NULL};
    Item* p=start;
    for(int i=1;i<8;i++)
    {
        p->nxt=new Item{arr[i],NULL};
        p=p->nxt;
    }
    show(start);
    process(start);
    show(start);
}
