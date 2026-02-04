/*
 * @lc app=leetcode id=3637 lang=cpp
 *
 * [3637] Trionic Array I
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  bool isTrionic(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while (i < n - 1 && nums[i] < nums[i + 1]) ++i;
    int p = i;
    while (i < n - 1 && nums[i] > nums[i + 1]) ++i;
    int q = i;
    while (i < n - 1 && nums[i] < nums[i + 1]) ++i;

    return p != 0 && q != p && n - 1 != q && i == n - 1;
  }
};
// @lc code=end
