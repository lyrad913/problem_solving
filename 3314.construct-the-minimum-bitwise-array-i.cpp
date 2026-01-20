/*
 * @lc app=leetcode id=3314 lang=cpp
 *
 * [3314] Construct the Minimum Bitwise Array I
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ret;
    ret.reserve(nums.size());

    for (const auto& num : nums) {
      bool impossible = true;
      for (int i = 0; i < num; ++i) {
        if (((i | (i + 1)) == num)) {
          ret.push_back(i);
          impossible = false;
          break;
        }
      }
      if (impossible) ret.push_back(-1);
    }

    return ret;
  }
};
// @lc code=end
