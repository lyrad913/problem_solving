/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minimumDeletions(string s) {
    int n = s.length();
    int bPointer = 0, aPointer = bPointer + 1;

    int ret = 0;
    while (aPointer < n && bPointer < n) {
      if (s[bPointer] == 'b' && s[aPointer] == 'a') {
        ++bPointer;
        ++aPointer;
        ++ret;
      }
      while (bPointer < n && s[bPointer] != 'b') ++bPointer;
      aPointer = max(bPointer + 1, aPointer);
      while (aPointer < n && s[aPointer] != 'a') ++aPointer;
    }
    return ret;
  }
};
// @lc code=end
