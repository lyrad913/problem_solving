/*
 * @lc app=leetcode id=3047 lang=cpp
 *
 * [3047] Find the Largest Area of Square Inside Two Rectangles
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    int n = bottomLeft.size();
    long long maxLen = 0;

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        long long xLen = min(topRight[i][0], topRight[j][0]) -
                         max(bottomLeft[i][0], bottomLeft[j][0]);
        long long yLen = min(topRight[i][1], topRight[j][1]) -
                         max(bottomLeft[i][1], bottomLeft[j][1]);
        if (xLen > 0 && yLen > 0) {
          maxLen = max(maxLen, min(xLen, yLen));
        }
      }
    }
    return maxLen * maxLen;
  }
};
// @lc code=end
