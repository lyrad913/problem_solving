/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int ret = 0;
    for (int i = 0; i < nums.size() / 2; ++i) {
      int sum = nums[i] + nums[nums.size() - 1 - i];
      ret = max(sum, ret);
    }
    return ret;
  }
};
// @lc code=end
