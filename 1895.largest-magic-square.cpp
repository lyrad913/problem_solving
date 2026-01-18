/*
 * @lc app=leetcode id=1895 lang=cpp
 *
 * [1895] Largest Magic Square
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> rowSum;
  vector<vector<int>> colSum;
  vector<vector<int>> downDiagSum;
  vector<vector<int>> upDiagSum;
  bool isMagicSquare(int y, int x, int k, const vector<vector<int>>& grid) {
    int target = rowSum[y][x + k] - (x == 0 ? 0 : rowSum[y][x - 1]);
    // 가로합
    for (int i = 1; i <= k; ++i) {
      if (target != rowSum[y + i][x + k] - (x == 0 ? 0 : rowSum[y + i][x - 1]))
        return false;
    }

    // 세로합
    for (int i = 0; i <= k; ++i) {
      if (target != colSum[y + k][x + i] - (y == 0 ? 0 : colSum[y - 1][x + i]))
        return false;
    }

    // 하방대각합
    if (target != downDiagSum[y + k][x + k] -
                      ((x == 0 || y == 0) ? 0 : downDiagSum[y - 1][x - 1]))
      return false;

    // 상방대각합
    if (target !=
        upDiagSum[y + k][x] - ((y == 0 || x + k == upDiagSum[0].size() - 1)
                                   ? 0
                                   : upDiagSum[y - 1][x + k + 1]))
      return false;

    return true;
  }
  int largestMagicSquare(vector<vector<int>>& grid) {
    auto m = grid.size(), n = grid[0].size();
    rowSum = vector<vector<int>>(m, vector<int>(n, 0));
    colSum = vector<vector<int>>(m, vector<int>(n, 0));
    downDiagSum = vector<vector<int>>(m, vector<int>(n, 0));
    upDiagSum = vector<vector<int>>(m, vector<int>(n, 0));

    for (int y = 0; y < m; ++y) {
      for (int x = 0; x < n; ++x) {
        rowSum[y][x] = (x == 0) ? grid[y][x] : rowSum[y][x - 1] + grid[y][x];
        colSum[y][x] = (y == 0) ? grid[y][x] : colSum[y - 1][x] + grid[y][x];
        downDiagSum[y][x] = (y == 0 || x == 0)
                                ? grid[y][x]
                                : downDiagSum[y - 1][x - 1] + grid[y][x];
        upDiagSum[y][x] = (y == 0 || x == n - 1)
                              ? grid[y][x]
                              : upDiagSum[y - 1][x + 1] + grid[y][x];
      }
    }

    int maxK = 0;
    for (int y = 0; y < m; ++y) {
      for (int x = 0; x < n; ++x) {
        for (int k = 0; y + k < m && x + k < n; ++k) {
          if (isMagicSquare(y, x, k, grid)) maxK = max(maxK, k);
        }
      }
    }
    return maxK + 1;
  }
};
// @lc code=end
