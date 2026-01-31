/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    for (char letter : letters) {
      if (target - letter < 0) return letter;
    }
    return letters[0];
  }
};
// @lc code=end
