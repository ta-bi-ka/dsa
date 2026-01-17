#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> leaders;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int rp=n-1;
    leaders.push_back(a[rp]);
    for(int i=n-2;i>=0;i--){
        if(a[i]>=a[rp]){
            leaders.push_back(a[i]);
            rp=i;
        }
    }
    reverse(leaders.begin(), leaders.end());


    for(auto x:leaders){
        cout<<x<<" ";
    }


    return 0;
}