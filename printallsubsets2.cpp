#include<bits\stdc++.h>
using namespace std;

void printSubsets(vector<int> &arr,vector<int> &ans, int i)
{
    if(i==arr.size())
    {
        for(int val : ans)
        {
            cout<<val<<" ";
        }

        cout<<endl;
        return;


    }


    // include
    ans.push_back(arr[i]);
    printSubsets(arr,ans,i+1);

    // exclude
    ans.pop_back();
    printSubsets(arr,ans,i+1);

}

int main()

{
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    vector<int> ans;
    printSubsets(arr,ans,0);

    return 0;
}

