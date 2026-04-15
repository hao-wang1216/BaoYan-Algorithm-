#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510,M=10000+10;
int n,m,k;
int dist[N],backup[N];//每个点同时向外出发，需要对 dist[] 数组进行备份,串联效应
struct Edge{
    int a,b,w;
}edges[M];//每一次对每一个点的出边进行更新，单源最短路。一次循环就是一条边.
int bellman_ford(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=0;i<k;i++){
        memcpy(backup,dist,sizeof(dist));
        for(int j=0;j<m;j++){
            int a=edges[j].a;
            int b=edges[j].b;
            int w=edges[j].w;
            if(backup[a] < 0x3f3f3f3f / 2)
                dist[b] = min(dist[b], backup[a] + w);
        }
    }
    //if(dist[n]>0x3f3f3f3f/2) return -1;
    return dist[n];
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[i]={a,b,w};
    }
    int t=bellman_ford();
    if(t > 0x3f3f3f3f / 2) puts("impossible");
    else cout<<t<<endl;
}