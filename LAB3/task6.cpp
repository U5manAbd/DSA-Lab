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
        cout<<h->val;
        if(h->nxt) 
            cout<<"->";
        h=h->nxt;
    }
    cout<<"->NULL"<<endl;
}

void removeVal(Item*& start,int key)
{
    if(!start)
    {
        cout<<"List empty"<<endl;
        return;
    }

    if(start->val==key)
    {
        Item* gone=start;
        start=start->nxt;
        delete gone;
        cout<<"Deleted"<<endl;
        return;
    }

    Item* p=start;
    Item* q=NULL;

    while(p && p->val!=key)
    {
        q=p;
        p=p->nxt;
    }

    if(!p)
    {
        cout<<"Not found"<<endl;
        return;
    }

    q->nxt=p->nxt;
    delete p;
    cout<<"Deleted"<<endl;
}

int main()
{
    int arr[]={5,15,25,35,45};
    Item* start=new Item{arr[0],NULL};
    Item* cur=start;
    for(int i=1;i<5;i++)
    {
        cur->nxt=new Item{arr[i],NULL};
        cur=cur->nxt;
    }

    show(start);
    removeVal(start,25);
    show(start);
    removeVal(start,99);
    show(start);
}
