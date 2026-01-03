/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      if (*it < 9) {
        ++(*it);
        return digits;
      }
      *it = 0;
    }

    digits.insert(digits.begin(), 1);
    return digits;
  }
};
// @lc code=end
