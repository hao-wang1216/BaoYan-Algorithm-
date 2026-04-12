//什么遍历顺序？
#include<iostream>
using namespace std;
const int N=10;
int n;
int path[N];
bool visit[N];//是否访问过
void dfs(int u){
    if(u==n) {
        for(int i=0;i<n;i++) printf("%d ",path[i]);
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            path[u]=i;
            visit[i]=true;
            dfs(u+1);
            visit[i]=false;
        }
    }
}
int main(){
    cin>>n;
    dfs(0);//哪一个位置
    return 0;
}
// 1.DFS：递归结束条件的选择+状态标记+递归后的恢复
// 2.BFS：模拟队列 q[N], d[N] 使用d数组标记状态
// 3.搜索：解空间的搜索往往需要dfs+剪枝，bfs用来找最短路
// 4.树和图的存储：邻接表 h[N], e[N], ne[N], idx
// 5.树和图的遍历：遍历不用像搜索解空间一样递归后恢复，只用遍历一次即可