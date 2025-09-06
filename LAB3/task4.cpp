#include<iostream>
using namespace std;

struct Node{ 
    int val;
    Node* link; 
};

void show(Node* h){
    while(h)
    { 
        cout<<h->val;
        if(h->link)
         cout<<"->";
         h=h->link; 
        }
    cout<<"->NULL"<<endl;
}

Node* reorder(Node* h){
    if(!h||!h->link) return h;
    Node *eH=NULL,*eT=NULL,*oH=NULL,*oT=NULL,*p=h;
    while(p){
        if(p->val%2==0){
            if(!eH){
                 eH=p; eT=p;
                 }
            else
            {
                 eT->link=p; eT=eT->link;
                 }
        }
        else
        {
            if(!oH)
            { 
                oH=p; oT=p;
             }
            else{ oT->link=p; oT=oT->link; }
        }
        p=p->link;
    }
    if(!eH||!oH)
     return h;
    eT->link=oH; 
    oT->link=NULL; 
    return eH;
}

int main(){
    int a[]={8,12,10,5,4,1,6}; 
    Node* h=new Node{a[0],NULL}; 
    Node* c=h;

    for(int i=1;i<7;i++)
    { 
    c->link=new Node{a[i],NULL};
    c=c->link; 
    }
    
    show(h);
    h=reorder(h);
    show(h);
}
