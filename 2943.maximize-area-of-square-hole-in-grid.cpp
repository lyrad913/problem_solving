/*
 * @lc app=leetcode id=2943 lang=cpp
 *
 * [2943] Maximize Area of Square Hole in Grid
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int getMaxLength(const vector<int>& bars) {
    int len = 1, ret = 1;
    for (int i = 1; i < bars.size(); ++i) {
      if (bars[i] == bars[i - 1] + 1)
        ++len;
      else
        len = 1;
      ret = max(len, ret);
    }
    // 제거한 기둥수 + 1 이 길이
    return ret + 1;
  }
  int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                             vector<int>& vBars) {
    sort(vBars.begin(), vBars.end());
    sort(hBars.begin(), hBars.end());
    auto vLen = getMaxLength(vBars);
    auto hLen = getMaxLength(hBars);

    auto len = min(vLen, hLen);

    return len * len;
  }
};
// @lc code=end
