/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  // bottom이 주어졌을 때 해당 하는 피라미드를 만들 수 있는지 판단. 중복되는
  // 부분문제가 있을 것 같지만 시간이 여유가 있을 것으로 보이므로 우선 완전 탐색
  unordered_map<string, bool> cache;
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    // base case
    if (bottom.length() == 1) return true;
    if (cache.find(bottom) != cache.end()) return cache[bottom];
    cache[bottom] = buildNextBottom(bottom, "", 0, allowed);
    return cache[bottom];
  }

  bool buildNextBottom(string bottom, string next_bottom, int idx,
                       vector<string>& allowed) {
    // base case
    if (idx == bottom.length() - 1)
      return pyramidTransition(next_bottom, allowed);

    for (auto e : allowed) {
      if (e[0] == bottom[idx] && e[1] == bottom[idx + 1]) {
        if (buildNextBottom(bottom, next_bottom + e[2], idx + 1, allowed))
          return true;
      }
    }
    return false;
  }
};
// @lc code=end
