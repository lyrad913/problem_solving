/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  // 시간 복잡도의 여유가 있으니 그냥 다 돌자
  int countNegatives(vector<vector<int>>& grid) {
    int cnt = 0;
    for (auto row : grid) {
      for (auto elem : row) {
        if (elem < 0) cnt++;
      }
    }

    return cnt;
  }
};
// @lc code=end
