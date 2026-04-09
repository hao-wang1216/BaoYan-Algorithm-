#include<iostream>

using namespace std;
const int N=1e5+10;
int stk[N],tt;
int main(){
    int n;
    cin>>n;
    //维护单调性,单调增，栈顶元素比新输入的数字大就pop
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(tt&&stk[tt]>=x) tt--;//把所有>=x的全部删掉
        if(tt)printf("%d ",stk[tt]);
        else printf("-1 ");
        stk[++tt]=x;
    }
    return 0;
    
}
