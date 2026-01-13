/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ret = 0;
    for (int i = 0; i < points.size() - 1; ++i) {
      //   int diag = min(abs(points[i][0] - points[i + 1][0]),
      //                  abs(points[i][1] - points[i + 1][1]));
      int bigger = max(abs(points[i][0] - points[i + 1][0]),
                       abs(points[i][1] - points[i + 1][1]));
      ret += bigger;
    }
    return ret;
  }
};
// @lc code=end
