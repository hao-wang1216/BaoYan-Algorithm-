//枚举“中转点 k”，不断尝试 i → k → j 是否更优
#include<iostream>
#include<cstring>
using namespace std;

const int N = 210;
const int INF = 0x3f3f3f3f;

int n, m,Q;
int dist[N][N];

int main(){
    cin >> n >> m>> Q;
  
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        dist[a][b]=min(dist[a][b],w);
    }
    // Floyd
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    while(Q--){
        int x,y;
        cin>>x>>y;
        int t=dist[x][y];
        if(t > INF / 2) puts("impossible");
        else cout <<t << endl;
    }
    return 0;
}