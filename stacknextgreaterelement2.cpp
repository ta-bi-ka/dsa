#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (s.size() > 0 && nums[s.top()] <= nums[i % n]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i % n] = nums[s.top()];
        }
        s.push(i % n);
    }

    return result;
}