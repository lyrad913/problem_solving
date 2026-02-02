/*
 * @lc app=leetcode id=3010 lang=cpp
 *
 * [3010] Divide an Array Into Subarrays With Minimum Cost I
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minimumCost(vector<int>& nums) {
    sort(nums.begin() + 1, nums.end());

    return nums[0] + nums[1] + nums[2];
  }
};
// @lc code=end
