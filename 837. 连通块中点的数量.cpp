#include<iostream>
using namespace std;

const int N=1e5+10;
int p[N],s[N];
int n,m;

int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);//找到 x 所在集合的“祖宗节点（根节点）”，并顺便把路径压缩
    return p[x];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;//自己是自己的祖宗
        s[i]=1;
    }
    while(m--){
        char op[3];
        int a,b;
        cin>>op;
        if(op[0]=='C'){
            scanf("%d%d",&a,&b);
            //不在一个集合中再合并
            if(find(a)!=find(b)) {
                s[find(b)] += s[find(a)];
                p[find(a)] = find(b);
                // s[find(a)]+=s[find(b)];//合并大小
                // p[find(a)]=find(b);//合并两个集合
            }
        }
        
        else if(op[1]=='1'){
            scanf("%d%d",&a,&b);
            if(find(a)==find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        
        else{
            scanf("%d",&a);
            cout<<s[find(a)]<<'\n';
        }
    }
    return 0;
}