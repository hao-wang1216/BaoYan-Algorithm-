#include<iostream>
#include<string>
using namespace std;
const int N=1e5+10;
int son[N][26],idx;
int cnt[N];
void insert(string s){
    int p=0;
    for(int i=0;i<s.size();i++){
        int u=s[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}
int query(string s){
    int p=0;
    for(int i=0;i<s.size();i++){
        int u=s[i]-'a';
        if(!son[p][u]) return 0 ;
        p=son[p][u];
    }
    return cnt[p];
}
int main(){
    int n;
    cin>>n;
    while(n--){
        char op;
        string s;
        cin>>op>>s;
        if(op=='I') insert(s);
        else {
            int ans=query(s);
            cout<<ans<<endl;
        }
    }
}
