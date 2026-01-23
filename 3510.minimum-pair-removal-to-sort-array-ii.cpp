/*
 * @lc app=leetcode id=3510 lang=cpp
 *
 * [3510] Minimum Pair Removal to Sort Array II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  struct Item {
    long long sum;  // can be 1e14
    int idx1;
    int idx2;
    bool operator<(const Item& item) const {
      if (this->sum == item.sum) {
        return this->idx1 < item.idx1;
      } else {
        return this->sum < item.sum;
      }
    }
    bool operator>(const Item& item) const {
      if (this->sum == item.sum) {
        return this->idx1 > item.idx1;
      } else {
        return this->sum > item.sum;
      }
    }
  };

  bool isNonDecreasing(const vector<int>& nums) { return badPoints == 0; }

  int badPoints = 0;

  int minimumPairRemoval(vector<int>& nums) {
    int numOperations = 0;
    priority_queue<Item, vector<Item>, greater<Item>> pq;
    vector<int> prevIdx(nums.size(), -1);
    vector<int> nextIdx(nums.size(), -1);
    vector<long long> vals(nums.size(), 0);

    for (int i = 0; i < nums.size(); ++i) {
      if (i != nums.size() - 1) {
        pq.push({nums[i] + nums[i + 1], i, i + 1});
        if (nums[i + 1] < nums[i]) badPoints++;
      }
      prevIdx[i] = i - 1;
      nextIdx[i] = i + 1;
      vals[i] = nums[i];
    }

    while (!isNonDecreasing(nums) && !pq.empty()) {
      Item item = pq.top();
      pq.pop();

      auto sum = item.sum;
      int idx1 = item.idx1, idx2 = item.idx2;

      // 유효한 아이템인가?
      if ((nextIdx[idx1] != idx2) || (prevIdx[idx2] != idx1) ||
          (sum != vals[idx1] + vals[idx2]))
        continue;

      // 합쳤을 때 발생하는 변화 반영
      // 합치는 두 원소의 관계
      if (vals[idx2] < vals[idx1]) {
        badPoints--;
      }

      // 합치고 난 후 정렬이 깨지거나, 생기거나.
      // 합친 후 왼쪽 과의 관계
      int p = prevIdx[idx1];
      if (p != -1) {
        if (vals[p] > sum)  // 정렬 깨짐
          badPoints++;
        if (vals[p] > vals[idx1])  // 정렬 생김
          badPoints--;
      }

      // 합친 후 오른쪽과의 관계
      int n = nextIdx[idx2];
      if (n != nums.size()) {
        if (vals[idx2] > vals[n])  // 정렬 생김
          badPoints--;
        if (sum > vals[n])  // 정렬 깨짐
          badPoints++;
      }

      // 업데이트(논리적으로 idx2 지우기)
      vals[idx1] = sum;
      nextIdx[idx1] = n;
      if (n < nums.size()) prevIdx[n] = idx1;

      // 큐 등록
      if (p != -1) pq.push({vals[p] + vals[idx1], p, idx1});
      if (n < nums.size()) pq.push({vals[idx1] + vals[n], idx1, n});

      numOperations++;
    }

    return numOperations;
  }
};
// @lc code=end
