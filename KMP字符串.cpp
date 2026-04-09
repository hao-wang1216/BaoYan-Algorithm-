#include <iostream>

using namespace std;
const int N=1e6+10,M=1e5+10;
char s[N],p[M];
int ne[M];
int n, m;

int main(){
    cin >> m >> p+1 >> n >> s+1;
    //next数组
    for(int i=2,j=0;i<=m;i++){
        //j: 当前已经匹配成功的长度
        //i: 当前处理到模式串 p[i]
        //不匹配上->回退
        while(j&&p[i]!=p[j+1]) j=ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i]=j;
    }
    //i：扫描到主串的那个字符
    //j: 当前已经匹配了模式串前 j 个字符
    for(int i=1,j=0;i<=n;i++){
        while(j&&s[i]!=p[j+1]) j=ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==m) {
            printf("%d ",i-m);
            j=ne[j];
        }
    }
    return 0;
    
}