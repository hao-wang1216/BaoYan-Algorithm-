#include<iostream>
using namespace std;
const int N=1e6+10;

int n;
int stk[N],tt;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(tt&&stk[tt]>=x) tt--;//维护单调性
        //如果一个数比当前数大，它永远不可能成为答案
        if(tt) printf("%d ",stk[tt]);
        else printf("-1 ");
        stk[++tt]=x;
    }
    return 0; 
}