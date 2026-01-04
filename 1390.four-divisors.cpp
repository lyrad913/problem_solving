/*
 * @lc app=leetcode id=1390 lang=cpp
 *
 * [1390] Four Divisors
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> n_divisor = vector<int>(1e5 + 1, 1);
  vector<int> sum = vector<int>(1e5 + 1, 1);

  int sumFourDivisors(vector<int>& nums) {
    for (int i = 2; i <= 1e5; ++i) {
      for (long long j = i; j <= 1e5; j += i) {
        n_divisor[j]++;
        sum[j] += i;
      }
    }
    int ret = 0;
    for (auto num : nums) {
      if (n_divisor[num] == 4) {
        ret += sum[num];
      }
    }
    return ret;
  }
};
// @lc code=end
