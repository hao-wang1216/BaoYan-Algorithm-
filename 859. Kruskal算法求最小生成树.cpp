#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,m;
int p[N];//并查集
struct Edge{
    int a,b,w;
    bool operator < (const Edge &t) const{
        return w<t.w;
    }
}Edge[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int Kruskal(){
    sort(Edge,Edge+m);
    int res=0,cnt=0;
    for(int i=1;i<=n;i++) p[i]=i;
    //按顺序遍历每条边,不在集合中就合并
    for(int i=0;i<m;i++){
        int a=Edge[i].a;
        int b=Edge[i].b;
        int c=Edge[i].w;
        int pa=find(a),pb=find(b);
        if(pa!=pb){ 
            p[find(a)]=find(b);
            res+=c;
            cnt++;
        }
    }
    if(cnt<n-1) return -1;
    else return res;
}

int main(){
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Edge[i]={a,b,c};
    }
    int t=Kruskal();
    if(t==-1) cout<<"impossible"<<endl;
    else cout<<t<<endl;
}