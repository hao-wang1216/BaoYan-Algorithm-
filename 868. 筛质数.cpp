#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int prime[N];
int cnt;
bool st[N];

int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(!st[i]){
            prime[cnt++]=i;
            for(int j=i*2;j<=n;j+=i){
                st[j]=true;
            }
        }
    }
    cout<<cnt<<endl;
}

