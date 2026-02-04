/*
 * @lc app=leetcode id=3640 lang=cpp
 *
 * [3640] Trionic Array II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
  long long INF = 1e14 + 1;

 public:
  long long maxSumTrionic(vector<int>& nums) {
    int n = nums.size();
    vector<long long> sums(n, nums[0]);
    for (int i = 1; i < n; ++i) sums[i] = nums[i] + sums[i - 1];

    array<int, 4> indices = {0, -1, -1, -1};
    auto& [l, p, q, r] = indices;
    int i = 0;
    long long ret = -INF;
    bool new_begin = true;
    int l_best = 0, next_l_best = 0;
    while (i < n - 1) {
      if (new_begin) {
        // 1. l 찾기
        while (i < n - 1 && nums[i] >= nums[i + 1]) l = ++i;
        // 2. 증가 구간 중 합을 최대로 하는 시작점 찾기
        long long min_prefix = (i > 0) ? sums[i - 1] : 0;
        l_best = i;
        while (i < n - 1 && nums[i] < nums[i + 1]) {
          if (0 < i && sums[i - 1] < min_prefix) {
            min_prefix = sums[i - 1];
            l_best = i;
          }
          ++i;
        }
        p = i;
      }
      while (i < n - 1 && nums[i] > nums[i + 1]) ++i;
      q = i;

      long long min_prefix = sums[i - 1];
      next_l_best = i;
      while (i < n - 1 && nums[i] < nums[i + 1]) {
        if (sums[i - 1] < min_prefix) {
          min_prefix = sums[i - 1];
          next_l_best = i;
        }
        ++i;
        ret = max(ret, sums[i] - (l_best > 0 ? sums[l_best - 1] : 0));
      }
      r = i;
      if (l < p && p < q && q < r) {
        l = q;
        p = r;
        l_best = next_l_best;
        new_begin = false;
      } else {
        l = i;
        new_begin = true;
      }
    }
    return ret;
  }
};
// @lc code=end
