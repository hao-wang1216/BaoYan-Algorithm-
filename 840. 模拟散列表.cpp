#include <iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int n;
int h[N],e[N],ne[N],idx;
void insert(int x){
    int k=(x%N+N)%N;//负数情况
    //从插入槽中
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;
}
bool find(int x){
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i]){
        if(e[i]==x) return true;
    }
    return false;
}
int main(){
    cin>>n;
    memset(h,-1,sizeof(h));
    while(n--){
        char op[2];
        int x;
        cin>>op>>x;
        if(op[0]=='I') insert(x);
        else {
            if(find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}