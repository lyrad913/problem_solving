/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int countBinarySubstrings(string s) {
    vector<int> numOfConsequcutive;

    auto prev = s[0];
    int cnt = 0;
    for (auto ch : s) {
      if (prev == ch)
        cnt++;
      else {
        numOfConsequcutive.emplace_back(cnt);
        cnt = 1;
        prev = ch;
      }
    }
    numOfConsequcutive.emplace_back(cnt);

    int ret = 0;
    for (int i = 0; i < numOfConsequcutive.size() - 1; ++i) {
      ret += min(numOfConsequcutive[i], numOfConsequcutive[i + 1]);
    }

    return ret;
  }
};
// @lc code=end
