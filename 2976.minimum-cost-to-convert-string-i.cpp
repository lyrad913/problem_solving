/*
 * @lc app=leetcode id=2976 lang=cpp
 *
 * [2976] Minimum Cost to Convert String I
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  long long minimumCost(string source, string target, vector<char>& original,
                        vector<char>& changed, vector<int>& cost) {
    int num_char = 'z' - 'a' + 1;
    vector<vector<int>> min_costs(num_char, vector<int>(num_char, -1));
    for (int i = 0; i < num_char; ++i) {
      min_costs[i][i] = 0;
    }

    for (int i = 0; i < original.size(); ++i) {
      int from = original[i] - 'a';
      int to = changed[i] - 'a';
      int& c = min_costs[from][to];
      c = c == -1 ? cost[i] : min(c, cost[i]);
    }

    for (int mid = 0; mid < num_char; ++mid) {
      for (int from = 0; from < num_char; ++from) {
        if (from != mid)
          for (int to = 0; to < num_char; ++to) {
            if (to != mid && from != to) {
              if (min_costs[from][mid] != -1 && min_costs[mid][to] != -1) {
                min_costs[from][to] =
                    min_costs[from][to] == -1
                        ? min_costs[from][mid] + min_costs[mid][to]
                        : min(min_costs[from][to],
                              min_costs[from][mid] + min_costs[mid][to]);
              }
            }
          }
      }
    }

    long long ret = 0;
    for (int i = 0; i < source.length(); ++i) {
      int from = source[i] - 'a';
      int to = target[i] - 'a';
      int& c = min_costs[from][to];

      if (c == -1) return -1;
      ret += (long long)c;
    }
    return ret;
  }
};
// @lc code=end
