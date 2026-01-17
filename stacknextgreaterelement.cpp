#include<bits\stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreaterMap;
    stack<int> s;
    for (int i=nums2.size()-1;i>= 0;i--) {
        int num = nums2[i];
        while (s.size() >0 && s.top() < num) {
            s.pop();
        }
        if(s.empty())
        {
            nextGreaterMap[num] = -1;
        }
        else
        {
            nextGreaterMap[num] = s.top();
        }
        s.push(num);
    }
    vector<int> result;
                // for (int num : nums1) {
                //     result.push_back(nextGreaterMap[num]);
                // }
    for (int i=0;i<nums1.size();i++) {
        result.push_back(nextGreaterMap[nums1[i]]);
    }

    return result;
}