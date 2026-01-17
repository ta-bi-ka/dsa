#include<bits\stdc++.h>
using namespace std;
// int trappingRainWater(vector<int>& heights) {
//     int n = heights.size();
//     vector<int> leftMax(n, 0), rightMax(n, 0);
    
//     leftMax[0] = heights[0];
//     rightMax[n - 1] = heights[n - 1];
//     for (int i = 1; i < n; i++) {
//         leftMax[i] = max(leftMax[i - 1], heights[i]);
//     }
//     for (int i = n - 2; i >= 0; i--) {
//         rightMax[i] = max(rightMax[i + 1], heights[i]);
//     }

//     int totalWater = 0;
//     for (int i = 0; i < n; i++) {
//         totalWater += min(leftMax[i], rightMax[i]) - heights[i];
//     }
//     return totalWater;
// }





int trap(vector<int>& height)
{
    int n = height.size();
    if (n == 0) return 0;
    int totalWater = 0;
    int l=0;
    int r=n-1;
    int lmax=0;
    int rmax=0;
    while(l<=r) {
        lmax=max(lmax,height[l]);
        rmax=max(rmax,height[r]);
        if(lmax < rmax) {
            totalWater += lmax - height[l];
            l++;
        } else {
            totalWater += rmax - height[r];
            r--;
        }

        return totalWater;

    }

}