/*
 * @lc app=leetcode id=3719 lang=cpp
 *
 * [3719] Longest Balanced Subarray I
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int longestBalanced(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      unordered_set<int> even, odd;
      for (int j = i; j < nums.size(); ++j) {
        if (nums[j] % 2 == 0)
          even.emplace(nums[j]);
        else
          odd.emplace(nums[j]);
        if (even.size() == odd.size()) {
          //   cout << j << ", " << i << endl;
          ret = max(j - i + 1, ret);
        }
      }
    }
    return ret;
  }
};
// @lc code=end
