#include<iostream>
using namespace std;

struct Node{ 
    int val; Node* link; 
};

void show(Node* p){ 
    while(p){ 
        cout<<p->val<<" "; 
        p=p->link; 
    } 
    cout<<endl; 
}

Node* insertFront(Node* h,int x){
    Node* q=new Node{x,h}; 
    return q;
}

void insertEnd(Node* h,int x){
    while(h->link) h=h->link; 
    h->link=new Node{x,NULL};
}

void insertAt(Node* h,int x,int pos){
    int cnt=1; 
    while(h && cnt<pos-1){ 
        h=h->link; 
        cnt++; 
    }
    if(h){ 
        Node* m=new Node{x,h->link}; 
        h->link=m; 
    }
}

Node* removeVal(Node* h,int x){
    if(!h) return h; 
    if(h->val==x){ 
        Node* d=h; 
        h=h->link; 
        delete d; 
        return h; 
    }
    Node* t=h; 
    while(t->link && t->link->val!=x) 
        t=t->link;
    if(t->link){ 
        Node* d=t->link; 
        t->link=t->link->link; 
        delete d; 
    }
    return h;
}

int main(){
    int a[5]={3,1,2,5,8}; 
    for(int i=0;i<5;i++) 
        cout<<a[i]<<" "; 
    cout<<endl;

    Node* h=new Node{a[0],NULL}; 
    Node* c=h; 
    for(int i=1;i<5;i++){ 
        c->link=new Node{a[i],NULL}; 
        c=c->link; 
    }

    insertEnd(h,9); 
    insertAt(h,11,3); 
    h=insertFront(h,4);

    h=removeVal(h,1); 
    h=removeVal(h,2); 
    h=removeVal(h,5);

    show(h);
}
