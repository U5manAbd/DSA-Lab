 #include <iostream>
 using namespace std;
 class result{
 public:
    int idx[100];
    int count;
    result(){
        count=0;
        for(int i=0;i<100;i++) idx[i]=-1;
    }
 };
 class rabinkarp{
    int p=101;
    int d=256;
 public:
    result rk(string text,string pat){
        result r;
        int n=text.length();
        int m=pat.length();
        long long phash=0,thash=0,h=1;
        for(int i=0;i<m-1;i++) h=(h*d)%p;
        for(int i=0;i<m;i++){
            phash=(d*phash + pat[i])%p;
            thash=(d*thash + text[i])%p;
        }
        for(int i=0;i<=n-m;i++){
            if(phash==thash){
                bool match=true;
                for(int j=0;j<m;j++){
                    if(text[i+j]!=pat[j]){
                        match=false;
                        cout<<"false positive at "<<i<<endl;
                        break;
                    }
                }
                if(match){
                    r.idx[r.count]=i;
                    r.count++;
                }
            }
            if(i<n-m){
                thash=(d*(thash - text[i]*h) + text[i+m])%p;
                if(thash<0) thash+=p;
            }
        }
        return r;
    }
 };
int main(){
    string txt="Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pat="Algorithms";
    rabinkarp rks;
    result r=rks.rk(txt,pat);
    cout<<"pattern found at indices: ";
    for(int i=0;i<r.count;i++) cout<<r.idx[i]<<" ";
    cout<<endl;
 }