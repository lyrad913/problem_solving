/*
 * @lc app=leetcode id=3713 lang=cpp
 *
 * [3713] Longest Balanced Substring I
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int longestBalanced(string s) {
    int n = s.length();
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      int alphas[26];
      memset(alphas, 0, sizeof(alphas));
      for (int j = i; j < n; ++j) {
        int ch = s[j] - 'a';
        alphas[ch]++;
        bool balanced = true;
        for (int k = 0; k < 26; ++k)
          if (alphas[k] > 0 && alphas[k] != alphas[ch]) {
            balanced = false;
            break;
          }
        if (balanced) ret = max(ret, j - i + 1);
      }
    }
    return ret;
  }
};
// @lc code=end
