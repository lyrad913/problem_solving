/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  string addBinary(string a, string b) {
    string ret = "";
    int carry = 0;
    auto ita = a.rbegin(), itb = b.rbegin();
    while (ita != a.rend() || itb != b.rend() || carry != 0) {
      int sum = carry;
      if (ita != a.rend()) {
        sum += ((*ita) == '1') ? 1 : 0;
        ++ita;
      }
      if (itb != b.rend()) {
        sum += ((*itb) == '1') ? 1 : 0;
        ++itb;
      }

      ret = ((sum % 2 == 1) ? "1" : "0") + ret;
      carry = sum / 2;
    }
    return ret;
  }
};
// @lc code=end
