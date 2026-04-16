#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510;
#define INF 0x3f3f3f3f 
int g[N][N],dist[N];
bool st[N];
int n,m;

int prim(){
    memset(dist,0x3f,sizeof(dist));
    int res=0;
    for(int i=0;i<n;i++){
        int t=-1;
        //选中集合之外的距离最短的点。
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])) {t=j;}
        }
        //归并点,将点放到集合里边
        if(i&&dist[t]==INF) return INF;//如果不是第一个点并且dist==INF说明不连通
        if(i) res+=dist[t];//只要不是第一个点
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],g[t][j]);
        }
        st[t]=true;
    }
    return res;
}
int main(){
    memset(g,0x3f,sizeof(g));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int t=prim();
    if(t==0x3f3f3f3f) cout<<"impossible";
    else cout<<t<<endl;
}
