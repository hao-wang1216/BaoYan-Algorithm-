#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=130;
int n,m;
typedef pair<int,int>PII;
queue<PII> q;
int g[N][N];
int d[N][N];
int dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
int bfs(){
    memset(d,-1,sizeof(d));
    q.push({0,0});
    d[0][0]=0;
    while (!q.empty()){
        auto t=q.front();
        q.pop();//取队头元素
        //四个方向扩展队列
        for(int i=0;i<4;i++){
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0&&d[x][y]==-1){
                q.push({x,y});
                d[x][y] = d[t.first][t.second] + 1;//路径+1
            }
        }
    }
    return d[n-1][m-1];
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    cout<<bfs()<<endl;
}