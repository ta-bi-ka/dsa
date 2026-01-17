#include<bits\stdc++.h>
using namespace std;

vector<int> previoussmallerElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
       while(s.size() > 0 && s.top() > nums[i]) {
           s.pop();
       }
         if(!s.empty()) {
              result[i] = s.top();
         }
         
            s.push(nums[i]);

    }

    return result;
}