/*
 * @lc app=leetcode id=3379 lang=cpp
 *
 * [3379] Transformed Array
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ret(n);

    for (int i = 0; i < n; ++i) {
      int j = i + nums[i];
      while (j < 0) j += n;
      int idx = j % n;
      //   if (j < 0) {
      //     idx = (-idx + n) % n;
      //   }
      cout << j << " " << idx << endl;
      ret[i] = nums[idx];
    }
    return ret;
  }
};
// @lc code=end
