/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int ret = 0;

    for (int y = 0; y < matrix.size(); ++y) {
      for (int x = 0; x < matrix[y].size(); ++x) {
        if (matrix[y][x] == '1') {
          int min_x = matrix[y].size() - x;
          int candi = 1;
          for (int next_y = y; next_y < matrix.size(); ++next_y) {
            for (int next_x = x;; ++next_x) {
              if (next_x == matrix[y].size() || matrix[next_y][next_x] == '0') {
                min_x = min(min_x, next_x - x);

                break;
              }
            }
            candi = max(candi, (next_y - y + 1) * min_x);
          }
          ret = max(ret, candi);
        }
      }
    }

    return ret;
  }
};
// @lc code=end
