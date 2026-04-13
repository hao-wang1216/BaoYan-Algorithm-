//树的重心是使得删除该节点后，最大连通块最小的节点，其本质是对子树规模的平衡优化。
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
const int M=2*N;
int h[N],e[N],ne[M],idx;
int n;
bool st[N];
int ans=N;//最小最大连通块
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
//以u为根的子树的点的数量
int dfs(int u){
    st[u]=true;
    int sum=1; // 当前子树的大小
    int res=0; // 删除 u 后的最大子树
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            int s=dfs(j);//子树的大小
            sum += s;
            res=max(s,res);// 更新最大子树
            
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}
int main(){
    memset(h,-1,sizeof(h));
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    
}