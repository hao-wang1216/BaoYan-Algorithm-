#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int q[N],d[N];//数组模拟队列，d表示ru度
int n,m;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
    d[b]++;
}
bool topo(){
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            q[++tt]=i;
        }
    }
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            d[j]--;
            if(d[j]==0)q[++tt]=j;
        }
    }
    return tt==n-1;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    if(topo()){
        for(int i=0;i<n;i++){
            cout<<q[i]<<" ";
        }
    }
    else printf("-1");
    return 0;
}