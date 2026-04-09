#include<iostream>
using namespace std;

const int N=1e6+10;
int a[N];

int q[N],hh=0,tt=-1;//单调队列,队列中存的是元素下标

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(hh<=tt&&i-k+1>q[hh])hh++;//维护元素个数
        while(hh<=tt&&a[q[tt]]>a[i])tt--;//新插入的元素比队尾元素小那就把队尾删掉，最小值
        q[++tt]=i;
        if(i>=k-1) printf("%d ",a[q[hh]]);//单调增队列
    }//最小值
    printf("\n");
    hh=0,tt=-1;
    for(int i=0;i<n;i++){
        if(hh<=tt&&i-k+1>q[hh])hh++;
        while(hh<=tt&a[q[tt]]<a[i]) tt--;//新插入的元素比队尾元素大那就把队尾删掉
        q[++tt]=i;
        if(i>=k-1) printf("%d ",a[q[hh]]);//单调减队列
    }
}