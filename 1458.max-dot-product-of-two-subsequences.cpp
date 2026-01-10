/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int len_nums1, len_nums2;
  vector<int> nums1, nums2;
  vector<vector<int>> cache;
  vector<vector<int>> visited;

  // idx1, idx2에서 시작하는 부분 배열들의 내적 최댓값을 반환한다.
  int maxDotProduct(int i, int j) {
    if (i == len_nums1 || j == len_nums2) return -1e9;
    if (visited[i][j]) return cache[i][j];
    visited[i][j] = 1;

    int cur_prod = nums1[i] * nums2[j];

    // 선택지:
    // 1. 현재 쌍을 쓴다 (뒤의 최적해가 양수면 더함)
    int take = cur_prod + max(0, maxDotProduct(i + 1, j + 1));
    // 2. i를 건너뛴다 (이게 for next1 루프를 대체)
    int skip_i = maxDotProduct(i + 1, j);
    // 3. j를 건너뛴다 (이게 for next2 루프를 대체)
    int skip_j = maxDotProduct(i, j + 1);

    return cache[i][j] = max({take, skip_i, skip_j});
  }

  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;

    len_nums1 = nums1.size();
    len_nums2 = nums2.size();

    cache = vector<vector<int>>(len_nums1, vector<int>(len_nums2, INT_MIN));
    visited = vector<vector<int>>(len_nums1, vector<int>(len_nums2, 0));

    return maxDotProduct(0, 0);
  }
};
// @lc code=end
