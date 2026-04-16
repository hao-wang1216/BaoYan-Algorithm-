///把图“涂成两种颜色”，且相邻点颜色不同
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int h[N],e[N],ne[N],idx;
int color[N];// 0=未染色, 1/2 表示两种颜色
int n,m;

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool dfs(int u,int c){
    color[u]=c;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!color[j]){
            if(!dfs(j,3-c)) return false; 
        }
        else if (color[j]==c) return false;
    }
    return true;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){//进行染色，在染色过程中遇到问题
                flag=false;
                break;
            }
        }
    }
    if(!flag)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}