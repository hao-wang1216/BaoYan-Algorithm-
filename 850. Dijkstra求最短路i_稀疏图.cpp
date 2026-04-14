//邻接表+堆优化的Dijkstra算法   
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int ,int >PII;//距离, 节点编号
const int N=2e5+10;//数据尽量开大
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second;
        int distance=t.first;//每次选中当前距离源点最近的点
        
        if(st[ver]) continue;
        st[ver] = true;
        //更新距离
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int k=dijkstra();
    cout<<k<<endl;
}