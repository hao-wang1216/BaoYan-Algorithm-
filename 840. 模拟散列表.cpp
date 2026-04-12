#include <iostream>
#include <cstring>
using namespace std;

const int N=2e6+10,null=0x3f3f3f3f;
// int h[N],e[N],ne[N],idx;
int h[N];
// void insert(int x){
//     //找到槽
//     int k=(x%N+N)%N;
//     e[idx]=x;
//     ne[idx]=h[k];
//     h[k]=idx++;
// }
// bool query(int x){
//     int k=(x%N+N)%N;
//     for(int i=h[k];i!=-1;i=ne[i]){
//         if(e[i]==x) return true;
//     }
//     return false;
// }
int find(int x){
    int k=(x%N+N)%N;
    while(h[k]!=null&&h[k]!=x){
        k++;
        if(k==N) k=0;
    }
    return k;
}
int main(){
    int n;
    cin>>n;
    memset(h,0x3f,sizeof(h));
    while(n--){
        char op[2];
        int x;
        cin>>op>>x;
        if(op[0]=='I'){
            int k=find(x);
            h[k]=x;
        }
        else{
            int k=find(x);
            if(h[k]!=null) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        
    }
}