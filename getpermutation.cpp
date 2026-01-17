#include<bits\stdc++.h>

using namespace std;

void getPermutationUtil(vector<int> &nums, int idx,vector<vector<int>> &result) {
    if (idx == nums.size()) {
        result.push_back({nums});
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        getPermutationUtil(nums, idx + 1, result);
        swap(nums[idx], nums[i]); // backtrack
    }
}

vector<vector<int>> getPermutations(vector<int> &nums) {
    vector<vector<int>> result;
    getPermutationUtil(nums, 0, result);
    return result;

}

int main() {
    vector<int> nums;


    // take input
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    vector<vector<int>> permutations = getPermutations(nums);
    
    for (const auto &perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}


