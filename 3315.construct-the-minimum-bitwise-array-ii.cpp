/*
 * @lc app=leetcode id=3315 lang=cpp
 *
 * [3315] Construct the Minimum Bitwise Array II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;
    ans.reserve(nums.size());

    for (auto num : nums) {
      if (num == 2) {
        ans.push_back(-1);
        continue;
      }

      for (int i = 1; i < 32; ++i) {
        if (!((num >> i) & 1)) {
          ans.push_back(num ^ (1 << (i - 1)));
          break;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
