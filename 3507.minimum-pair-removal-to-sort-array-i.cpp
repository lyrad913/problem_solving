/*
 * @lc app=leetcode id=3507 lang=cpp
 *
 * [3507] Minimum Pair Removal to Sort Array I
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isNonDecreasing(const vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i + 1]) return false;
    }
    return true;
  }
  int minimumPairRemoval(vector<int>& nums) {
    int numOperations = 0;
    while (true) {
      if (isNonDecreasing(nums)) break;
      int minSum = INT_MAX;
      auto pairIt = nums.end();
      for (auto it = nums.begin(); it != nums.end() - 1; ++it) {
        int sum = (*it) + (*(it + 1));
        if (sum < minSum) {
          minSum = sum;
          pairIt = it;
        }
      }
      nums.erase(pairIt, pairIt + 2);
      nums.insert(pairIt, minSum);
      ++numOperations;
    }
    return numOperations;
  }
};
// @lc code=end
