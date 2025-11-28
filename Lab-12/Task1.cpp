 #include<iostream>
 using namespace std;
 class result{
 public:
    int idx[100];
    int cmp;
    int count;
    result(){
        cmp=0;
        count=0;
        for(int i=0;i<100;i++) idx[i]=0;
    }
 };
 class searcher{
 public:
    result bf(string text, string pat){
        result r;
        int n=text.length();
        int m=pat.length();
        for(int i=0;i<=n-m;i++){
            int j;
            for(j=0;j<m;j++){
                r
 .cmp++;
                if(text[i+j]!=pat[j]) break;
            }
            if(j==m){
                r
 .idx[r.count]=i;
                r
 .count++;
            }
        }
        return r;
    }
 };
 int main(){
    string txt="the quick brown fox jumps over the lazy dog";
    string pat="the";
    searcher s;
    result r=s.bf(txt,pat);
    cout<<"pattern found at indices: ";
    for(int i=0;i<r.count;i++)
        cout<<r.idx[i]<<" ";
    cout<<endl<<"total comparisons: "<<r.cmp<<endl;
 }