

#include<bits\stdc++.h>
using namespace std;

int n;
int duration[1001];
int skill[1001];
int x,k;


int taken[1001];


bool check(int level)
{
    int timetaken=0;
    int itemtaken=0;
    for(int i=0;i<level;i++)
    {
        if(taken[i]==1)
        {
            timetaken+=duration[i];
            itemtaken++;
        }
    }

    timetaken+=duration[level];
    itemtaken++;

    if(timetaken<=x && itemtaken<=k)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int rec(int level)
{
    if(level==n)
    {
        return 0;
    }
    int ans=rec(level+1);
    if(check(level))
    {
        taken[level]=1;
        ans=max(ans,skill[level]+rec(level+1));
        taken[level]=0;
    }
    
    
    return ans;
}


int main()
{
    cin>>n>>x>>k;
    for(int i=0;i<n;i++)
    {
        cin>>duration[i]>>skill[i];
    }
    memset(taken,0,sizeof(taken));
    cout<<rec(0);
    return 0;
}









