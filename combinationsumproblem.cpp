#include <bits\stdc++.h>
using namespace std;
set<vector<int>> s;
void getallcombinations(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size() || target < 0)
    {
        return;
    }

    if (target == 0)
    {
        if (s.find(ds) == s.end())
        {
            ans.push_back(ds);
            s.insert(ds);
        }

        return;
    }
   

    // pick up the element

    ds.push_back(arr[ind]);
    getallcombinations(ind + 1, target - arr[ind], arr, ans, ds);
    getallcombinations(ind, target - arr[ind], arr, ans, ds);

    ds.pop_back();

    // not pick the element
    getallcombinations(ind + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    getallcombinations(0, target, candidates, ans, ds);
    return ans;
}

int main()
{
    vector<int> maze = {2, 3, 6, 7};

    int target = 7;

    vector<vector<int>> ans = combinationSum(maze, target);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}