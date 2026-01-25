#include <bits\stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(const vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> result;

    // process first window
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // process remaining windows
    for (int i = k; i < nums.size(); i++)
    {
        result.push_back(nums[dq.front()]);

        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // last window max
    result.push_back(nums[dq.front()]);
    return result;
}
