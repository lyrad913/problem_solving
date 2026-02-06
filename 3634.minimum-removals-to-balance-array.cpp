/*
 * @lc app=leetcode id=3634 lang=cpp
 *
 * [3634] Minimum Removals to Balance Array
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int ret = n;
    for (int l = 0, r = 0; l < n; ++l) {
      while (r < n && nums[r] <= (long long)nums[l] * k) {
        ++r;
      }
      ret = min(ret, n - (r - l));
    }

    return ret;
  }
};
// @lc code=end
