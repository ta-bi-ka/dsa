#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    int candidate=-1;
    for(int i=0;i<n;i++){
        if(count==0){
            candidate=a[i];
        }
        if(a[i]==candidate){
            count++;
        }else{
            count--;
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(a[i]==candidate){
            count++;
        }
    }
    if(count>n/2){
        cout<<candidate<<endl;
    }else{
        cout<<"No Majority Element"<<endl;
    }
    return 0;
}