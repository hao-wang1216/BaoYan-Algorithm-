//结点数目比较少的图
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=530;
int g[N][N],dist[N];
bool st[N];
int n,m;
int dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=1;i<=n;i++){
        //先找当前没有确定最短路长度的点当中，距离源点最短的一个
        int t=-1;//未选中
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t=j;
        }
        
        st[t]=true;
        //用这个点更新到其他点的距离
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    int t=dijkstra();
    cout<<t<<endl;
}