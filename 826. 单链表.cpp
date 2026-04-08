#include <iostream>
using namespace std;
const int N=1e6+10;
//idx是当前正在使用的位置
int head,e[N],ne[N],idx;
void init(){
    head=-1;//链表第一个节点的“下标”
    idx=0;
}
//在第K个位置后插入一个节点
void add(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}
void add_head(int x){
    e[idx]=x;
    ne[idx]=head;// 先把当前节点的next指向head的值
    head = idx;// head指向idx
    idx++;
}
void remove(int k){
    ne[k]=ne[ne[k]];
}
int main(){
    int m;
    cin>>m;
    init();
    while(m--){
        char op;
        cin>>op;
        if(op=='H'){
            int x;
            cin>>x;
            add_head(x);
        }
        else if(op=='D'){
            int k;
            cin>>k;
            //if()
            if(k == 0) head = ne[head];
            remove(k-1);
        }
        else if(op=='I'){
            int k,x;
            cin>>k>>x;
            add(k-1,x);//第k个数，下标k-1
        }
    }
    for(int i=head;i!=-1;i=ne[i]) cout<<e[i]<<' ';
}