/*
 * @lc app=leetcode id=2975 lang=cpp
 *
 * [2975] Maximum Square Area by Removing Fences From a Field
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int maximizeSquareArea(int m, int n, vector<int>& hFences,
                         vector<int>& vFences) {
    int mod = 1e9 + 7;

    hFences.insert(hFences.begin(), 1);
    hFences.insert(hFences.end(), m);
    vFences.insert(vFences.begin(), 1);
    vFences.insert(vFences.end(), n);
    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    vector<int> hDist;
    hDist.reserve(hFences.size() * hFences.size());
    for (int i = 0; i < hFences.size() - 1; ++i)
      for (int j = 0; j < hFences.size(); ++j)
        hDist.push_back(hFences[j] - hFences[i]);

    vector<int> vDist;
    vDist.reserve(vFences.size() * vFences.size());
    for (int i = 0; i < vFences.size() - 1; ++i)
      for (int j = 0; j < vFences.size(); ++j)
        vDist.push_back(vFences[j] - vFences[i]);

    sort(hDist.begin(), hDist.end());
    sort(vDist.begin(), vDist.end());

    int commonLongest = 0;
    for (auto hIt = hDist.rbegin(), vIt = vDist.rbegin();
         hIt != hDist.rend() && vIt != hDist.rend();) {
      if ((*hIt) == (*vIt)) {
        commonLongest = (*hIt);
        break;
      }
      if ((*hIt) < (*vIt)) {
        ++vIt;
      }
      if ((*vIt) < (*hIt)) {
        ++hIt;
      }
    }

    return commonLongest == 0
               ? -1
               : ((long long)commonLongest * (commonLongest % mod)) % mod;
  }
};
// @lc code=end
