/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long sum = 0;
    int n_minus = 0;
    int min_abs = 100001;
    for (auto row : matrix) {
      for (auto elem : row) {
        sum += abs(elem);
        min_abs = min(min_abs, abs(elem));
        if (elem < 0) {
          ++n_minus;
        }
      }
    }

    if (n_minus % 2 == 0)
      return sum;
    else
      return sum - 2 * min_abs;
  }
};
// @lc code=end
