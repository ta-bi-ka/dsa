#include<bits\stdc++.h>
using namespace std;

int   n;
int queen[20];
bool check(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        int prow=i;
        int pcol=queen[i];
        if(pcol==col || abs(prow-row)==abs(pcol-col))
        {
            return false;
        } 
        
    }
    return true;    
}
int rec(int level)
{
    if(level==n)
    {
        return 1;
    }
    int ans=0;
    for(int col=0;col<n;col++)
    {
        if(check(level,col))
        {
            queen[level]=col;
            ans+=rec(level+1);//porer row r jnno jodi kono column check kaj na kore n prjnto reach kore tahole automatic return krbe ager row te and ager row te j column e queen chilo oita -1 e replace hbe and porer column e mve krbe (ager row er)
            queen[level]=-1;
        }
    }
    return ans; 
}


int main()
{
    cin>>n;
    memset(queen,-1,sizeof(queen));
    cout<<rec(0);
    return 0;
}

