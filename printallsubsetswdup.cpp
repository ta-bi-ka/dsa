#include<bits\stdc++.h>

using namespace std;

void getallsubsets(vector<int> &nums, int index, vector<int> &ans,vector<vector<int>> &result)
{
    if(index==nums.size())
    {
        result.push_back(ans);
        return;
    }

    // include
    ans.push_back(nums[index]);
    getallsubsets(nums,index+1,ans,result);

    // exclude
    ans.pop_back();

    int i=index+1;
    while(i<nums.size() && nums[i]==nums[index])
    {
        i++;
    }
    getallsubsets(nums,i,ans,result);
}


vector<vector<int>> getallsubsetswithdup(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> ans;
    sort(nums.begin(),nums.end());
    getallsubsets(nums,0,ans,result);
    return result;
}

int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    vector<vector<int>> subsets = getallsubsetswithdup(nums);

    for(const auto &subset : subsets)
    {
        cout<<"{ ";
        for(int num : subset)
        {
            cout<<num<<" ";
        }
        cout<<"}"<<endl;
    }

    return 0;
}