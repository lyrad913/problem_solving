/*
 * @lc app=leetcode id=3013 lang=cpp
 *
 * [3013] Divide an Array Into Subarrays With Minimum Cost II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  long long minimumCost(vector<int>& nums, int k, int dist) {
    int n = nums.size();

    long long curSum = 0;
    set<pair<int, int>> smallest, other;

    for (int i = 1; i <= dist + 1; ++i) {
      smallest.emplace(nums[i], i);
      curSum += nums[i];
    }

    while (smallest.size() > k - 1) {
      auto it = prev(smallest.end());
      curSum -= it->first;
      other.emplace(*it);
      smallest.erase(it);
    }

    long long minSum = nums[0] + curSum;

    for (int i = dist + 2; i < n; ++i) {
      pair<int, int> toRemove = {nums[i - dist - 1], i - dist - 1};
      if (smallest.find(toRemove) != smallest.end()) {
        curSum -= toRemove.first;
        smallest.erase(toRemove);  // k-2
      } else {
        other.erase(toRemove);
      }

      pair<int, int> toAdd = {nums[i], i};
      //   smallest.insert(toAdd);  // k개 또는 k-1개
      //   curSum += toAdd.first;

      if (smallest.size() == k - 2) {
        if (!other.empty()) {
          auto it = other.begin();
          if ((*it).first > nums[i]) {
            smallest.insert(toAdd);
            curSum += toAdd.first;
          } else {
            smallest.insert(*it);
            curSum += it->first;
            other.erase(it);
            other.insert(toAdd);
          }
        } else {
          // other가 비어있으면 무조건 toAdd 추가
          smallest.insert(toAdd);
          curSum += toAdd.first;
        }
      } else if (smallest.size() == k - 1) {
        auto it = prev(smallest.end());
        if (it->first > nums[i]) {
          smallest.insert(toAdd);
          curSum = curSum + toAdd.first - it->first;
          other.insert(*it);
          smallest.erase(it);
        } else {
          other.insert(toAdd);
        }
      }

      minSum = min(minSum, nums[0] + curSum);
    }
    return minSum;
  }
};
// @lc code=end
