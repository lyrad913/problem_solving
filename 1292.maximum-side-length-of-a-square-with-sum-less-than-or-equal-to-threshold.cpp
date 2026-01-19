/*
 * @lc app=leetcode id=1292 lang=cpp
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to
 * Threshold
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> rowSums;
  int n, m;
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    n = mat.size();
    m = mat[0].size();
    rowSums = vector<vector<int>>(n, vector<int>(m, 0));

    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        rowSums[y][x] = (x == 0) ? mat[y][x] : rowSums[y][x - 1] + mat[y][x];
      }
    }

    for (int k = min(m, n); 1 <= k; k--) {
      for (int x = 0; x + k <= m; ++x) {
        int tempSum = 0;
        for (int y = 0; y < n; ++y) {
          tempSum += rowSums[y][x + k - 1] - (x == 0 ? 0 : rowSums[y][x - 1]);
          tempSum -= (k <= y) ? rowSums[y - k][x + k - 1] -
                                    (x == 0 ? 0 : rowSums[y - k][x - 1])
                              : 0;
          if (tempSum <= threshold && k - 1 <= y) return k;
        }
      }
    }
    return 0;
  }
};
// @lc code=end
