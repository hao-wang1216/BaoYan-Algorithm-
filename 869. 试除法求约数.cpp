#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> get(int n){
    vector <int> res;
    for(int i=1;i<=n/i;i++){
        if(n%i==0) {
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    
    sort(res.begin(),res.end());
    return res;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        auto t=get(x);
        for(auto k:t){
            cout<<k<<' ';
        }
        cout<<endl;
    }
    return 0;
}