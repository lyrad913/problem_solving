/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int diff = INT_MAX;
    for (int i = 0; i < arr.size() - 1; ++i)
      diff = min(diff, arr[i + 1] - arr[i]);

    vector<vector<int>> ret;
    for (int i = 0; i < arr.size() - 1; ++i)
      if (arr[i + 1] - arr[i] == diff) ret.push_back({arr[i], arr[i + 1]});

    return ret;
  }
};
// @lc code=end
