/*
 * @lc app=leetcode id=3074 lang=cpp
 *
 * [3074] Apple Redistribution into Boxes
 */
#include "bits/stdc++.h"

using namespace std;

// @lc code=start
// 오늘의 문제는 어렵지 않다!
// apple의 합계를 구하고, capacity 역순 정렬한 후에 커지면 멈추자
class Solution {
 public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int apple_cnt = 0;
    for (auto a : apple) apple_cnt += a;

    sort(capacity.rbegin(), capacity.rend());

    int capacity_sum = 0;
    for (int i = 0; i < capacity.size(); ++i) {
      capacity_sum += capacity[i];
      if (capacity_sum >= apple_cnt) return i + 1;
    }
    return 0;
  }
};
// @lc code=end
