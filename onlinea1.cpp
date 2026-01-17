#include<bits/stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
int maxsum=INT_MIN;
int cursum=0;
for(int i=0;i<n;i++)
{
    cursum+=a[i];
    maxsum=max(maxsum,cursum);
    if(cursum<0)
    {
        cursum=0;
    }

}
cout<<maxsum<<endl;

    return 0;
}