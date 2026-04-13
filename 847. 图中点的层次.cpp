#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int d[N];//从起点 1 到节点 x 的最短边数
int n,m;
queue<int>q;

void add(int a,int b){
    e[idx]=b;//存一下这个节点
    ne[idx]=h[a];//
    h[a]=idx++;
}
int bfs(){
    q.push(1);
    d[1]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(d[j]==-1){
                q.push(j);
                d[j]=d[t]+1;
            }
        }
    }
    return d[n];
}
int main(){
    cin>>n>>m;
    memset(d,-1,sizeof(d));
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs()<<endl;
}