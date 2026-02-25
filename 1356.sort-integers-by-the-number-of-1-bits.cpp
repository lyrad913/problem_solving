/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start

int countOne(int x) {
  x = x - ((x >> 1) & 0x55555555u);
  x = (x & 0x33333333u) + ((x >> 2) & 0x33333333u);
  x = (x + (x >> 4)) & 0x0F0F0F0Fu;
  x = x + (x >> 8);
  x = x + (x >> 16);
  return x & 0x3F;
}

bool compare(const int oa, const int ob) {
  int cntTwoA = countOne(oa);
  int cntTwoB = countOne(ob);
  if (cntTwoA == cntTwoB) return oa < ob;
  return cntTwoA < cntTwoB;
}

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), compare);
    return arr;
  }
};
// @lc code=end
