/*
 * @lc app=leetcode id=3453 lang=cpp
 *
 * [3453] Separate Squares I
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  double separateSquares(vector<vector<int>>& squares) {
    double hi = 0;
    double lo = 0;

    double total_area = 0;
    for (const auto& square : squares) {
      hi = max(hi, (double)(square[1] + square[2]));
      total_area += (double)square[2] * square[2];
    }

    double ret = (hi + lo) / 2;
    while (abs(hi - lo) > 1e-5) {
      double lower = 0;
      for (const auto& square : squares) {
        double y = square[1], l = square[2];
        if (y < ret) lower += l * min(l, ret - y);
      }

      // 기준 변경
      if (total_area / 2 <= lower)
        hi = ret;
      else
        lo = ret;
      ret = (hi + lo) / 2;
    }
    return ret;
  }
};
// @lc code=end
