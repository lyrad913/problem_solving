/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool is_magic_square(int y, int x, const vector<vector<int>>& grid) {
    // 가운데가 5가 아니면 합이 일정하지 않을 것 같은데... 증명은 못하겟음
    if (grid[y + 1][x + 1] != 5) return false;
    // 1~9가 한번씩만 등장하는지 체크
    vector<int> cnt(10, 0);
    for (int i = y; i - y < 3; ++i) {
      for (int j = x; j - x < 3; ++j) {
        if (grid[i][j] < 1 || grid[i][j] > 9) return false;
        if (cnt[grid[i][j]] != 0) return false;
        cnt[grid[i][j]]++;
      }
    }

    // 합이 일정한지 체크
    // 세로합
    if (grid[y][x] + grid[y + 1][x] + grid[y + 2][x] != 15) return false;
    if (grid[y][x + 1] + grid[y + 1][x + 1] + grid[y + 2][x + 1] != 15)
      return false;
    if (grid[y][x + 2] + grid[y + 1][x + 2] + grid[y + 2][x + 2] != 15)
      return false;
    // 가로합
    if (grid[y][x] + grid[y][x + 1] + grid[y][x + 2] != 15) return false;
    if (grid[y + 1][x] + grid[y + 1][x + 1] + grid[y + 1][x + 2] != 15)
      return false;
    if (grid[y + 2][x] + grid[y + 2][x + 1] + grid[y + 2][x + 2] != 15)
      return false;
    // 대각선
    if (grid[y][x] + grid[y + 1][x + 1] + grid[y + 2][x + 2] != 15)
      return false;
    if (grid[y + 2][x] + grid[y + 1][x + 1] + grid[y][x + 2] != 15)
      return false;
    return true;
  }
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    if (grid.size() < 3 || grid[0].size() < 3) return 0;
    int n_magic_square = 0;
    for (int y = 0; y <= grid.size() - 3; ++y) {
      for (int x = 0; x <= grid[y].size() - 3; ++x) {
        if (is_magic_square(y, x, grid)) ++n_magic_square;
      }
    }
    return n_magic_square;
  }
};
// @lc code=end
