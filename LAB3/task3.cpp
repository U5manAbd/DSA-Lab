#include<iostream>
#include<string>
using namespace std;

struct Passenger{ 
    string pname;
    Passenger* next; 
};

struct Flight{ 
    int fno;
    Flight* link;
     Passenger* plist; 
};

void addPassenger(Passenger* &h,string n){ 
    Passenger* p=new Passenger{n,NULL};
    if(!h||n<h->pname){
         p->next=h;
          h=p;
         return; 
        }
    Passenger* t=h; 
    while(t->next && t->next->pname<n) 
    t=t->next;
    p->next=t->next;
     t->next=p;
}

void removePassenger(Passenger* &h,string n){
    if(!h) 
    return;
    if(h->pname==n)
    { 
        Passenger* d=h; h=h->next;
         delete d;
         return;
     }
    Passenger* t=h; 
    while(t->next && t->next->pname!=n)
     t=t->next;
    if(t->next)
    { 
        Passenger* d=t->next; t->next=t->next->next;
         delete d;
         }
}

bool hasPassenger(Passenger* h,string n){
    while(h){ 
        if(h->pname==n) 
        return true;
         h=h->next; }
    return false;
}

void showPassengers(Passenger* h){
    while(h){ 
        cout<<h->pname<<endl; h=h->next; 
    }
}

Flight* findFlight(Flight* h,int fno){
    while(h){ 
        if(h->fno==fno)
         return h; 
         h=h->link; }
    return NULL;
}

void addFlight(Flight* &h,int fno){
    Flight* f=new Flight{fno,NULL,NULL};
    f->link=h;
     h=f;
}

int main(){
    Flight* flights=NULL; 
    int ch;
    do{
        cout<<"\n1.Add Flight\n2.Reserve\n3.Cancel\n4.Check\n5.Display\n6.Exit\nChoice: ";
        cin>>ch;
        if(ch==1){
            int fn; cout<<"Enter flight no: "; cin>>fn;
            addFlight(flights,fn);
        }
        else if(ch==2){
            int fn; string n; 
            cout<<"Flight no: "; cin>>fn; 
            cout<<"Name: "; cin>>n;
            Flight* f=findFlight(flights,fn);
            if(f) addPassenger(f->plist,n); 
            else cout<<"Flight not found\n";
        }
        else if(ch==3){
            int fn; string n; 
            cout<<"Flight no: "; cin>>fn; 
            cout<<"Name: "; cin>>n;
            Flight* f=findFlight(flights,fn);
            if(f) removePassenger(f->plist,n);
            else cout<<"Flight not found\n";
        }
        else if(ch==4){
            int fn; string n; 
            cout<<"Flight no: "; cin>>fn; 
            cout<<"Name: "; cin>>n;
            Flight* f=findFlight(flights,fn);
            cout<<(f && hasPassenger(f->plist,n)?"Reserved":"Not Reserved")<<endl;
        }
        else if(ch==5){
            int fn; cout<<"Flight no: "; cin>>fn;
            Flight* f=findFlight(flights,fn);
            if(f) showPassengers(f->plist);
            else cout<<"Flight not found\n";
        }
    }while(ch!=6);
}
