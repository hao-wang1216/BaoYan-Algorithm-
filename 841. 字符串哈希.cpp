#include<iostream>
using namespace std;
typedef unsigned long long ULL;
const int N=1e5+10;
ULL h[N],p[N];//h表示前缀字符的哈希值，p表示进制。
int P=131;//基数
char s[N];
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];//指数对齐
}
int main(){
    int n,m;
    scanf("%d%d%s",&n,&m,s+1);
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=P*p[i-1];
        h[i]=h[i-1]*P+s[i];//初始化前缀哈希值
    }
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1,r1)==get(l2,r2)){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}
