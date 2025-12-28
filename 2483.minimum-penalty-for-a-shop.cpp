/*
 * @lc app=leetcode id=2483 lang=cpp
 *
 * [2483] Minimum Penalty for a Shop
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
// solve(customers, close_time): close_time에 문을 닫았을 때 얻는 최소 패널티
// 최소페널티의 재귀 관계..?
// 끝에서 부터 오면서 보는게 맞는듯.
// customers[close_time]의 값이 중요한 듯 싶음. 증가함에 따라 Y면 +1, N이면 -1을
// 하면 되겠다.
class Solution {
 public:
  int bestClosingTime(string customers) {
    int min_penalty = 0;
    for (auto c : customers) {
      if (c == 'N') min_penalty++;
    }
    int penalty = min_penalty;

    int min_idx = customers.size();
    for (int i = customers.size() - 1; i >= 0; --i) {
      if (customers[i] == 'Y')
        penalty++;
      else
        penalty--;

      if (penalty <= min_penalty) {
        min_idx = i;
        min_penalty = penalty;
      }
    }
    return min_idx;
  }
};
// @lc code=end
