#include<bits\stdc++.h>
using namespace std;

int rec(int n,int level)
{
    if(level>n)
    return 0;
    if(level==n)
    {
        return 1;
    }

    int ans=0;
    for(int step=1;step<=3;step++)
    {
        if(level+step<=n)
        {
            ans+=rec(n,level+step);
        }
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;
    cout<<rec(n,0);
    return 0;
}