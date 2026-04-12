#include<iostream>

using namespace std;
const int N=20;
char g[N][N];
bool col[N],dg[N],udg[N];//对角线he列
int n;
void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++) cout<<g[i]<<endl;
        cout<<"\n";
        return;
    }
    //这一行上的某个位置
    for(int i=0;i<n;i++){
        if(!col[i]&&!dg[u+i]&&!udg[n-u+i]){
            col[i]=dg[u+i]=udg[n-u+i]=true;
            g[u][i]='Q';
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;
            g[u][i]='.';
            
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]='.';
        }
    }
    dfs(0);//从第0列开始搜
    return 0;
}