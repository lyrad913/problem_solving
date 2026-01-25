/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minimumDifference(vector<int>& nums, int k) {
    if (nums.size() == 1) return 0;
    sort(nums.begin(), nums.end());
    int ret = 10e5 + 1;
    for (int i = 0; i + k <= nums.size(); ++i) {
      ret = min(abs(nums[i] - nums[i + k - 1]), ret);
    }

    return ret;
  }
};
// @lc code=end
