/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> cache;
  string s1, s2;
  // s1[idx1:] s2[idx2:]의 최소반환
  int minimumDeleteSum(int idx1, int idx2) {
    // base case : 둘 다 빈 문자열
    if (idx1 == s1.size() && idx2 == s2.size()) return 0;

    int& ret = cache[idx1][idx2];
    if (ret != -1) return ret;

    // 둘 중 하나만 비어있는 경우
    if (idx1 == s1.size()) {
      ret = 0;
      for (int i = idx2; i < s2.size(); ++i) {
        ret += (int)s2[i];
      }
    }
    if (idx2 == s2.size()) {
      ret = 0;
      for (int i = idx1; i < s1.size(); ++i) {
        ret += (int)s1[i];
      }
    }
    if (idx1 != s1.size() && idx2 != s2.size()) {
      if (s1[idx1] == s2[idx2]) {
        ret = minimumDeleteSum(idx1 + 1, idx2 + 1);
      } else {
        ret = min((int)s1[idx1] + minimumDeleteSum(idx1 + 1, idx2),
                  (int)s2[idx2] + minimumDeleteSum(idx1, idx2 + 1));
      }
    }
    return ret;
  }
  int minimumDeleteSum(string s1, string s2) {
    cache = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    this->s1 = s1;
    this->s2 = s2;

    return minimumDeleteSum(0, 0);
  }
};
// @lc code=end
