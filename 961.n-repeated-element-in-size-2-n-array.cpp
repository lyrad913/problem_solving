/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 뭘 어떻게 해도 풀릴 수 밖에 없는 문제.
 * map을 써서 메모리를 더 쓸지
 * 정렬 후 이분탐색(lower_bound였나 처음으로 중복되는 원소를 찾는 함수가 있었던
 * 것 같음)을 해서 시간을 더 쓸지 선택하면 될 것 같다.
 */

// @lc code=start
class Solution {
 public:
  //   // solution 1
  //   int repeatedNTimes(vector<int>& nums) {
  //     unordered_map<int, int> m;
  //     for (auto num : nums) {
  //       if (m[num] != 0) return num;
  //       m[num]++;
  //     }
  //     return 0;
  //   }

  //   int repeatedNTimes(vector<int>& nums) {
  //     sort(nums.begin(), nums.end());
  //     auto it = adjacent_find(nums.begin(), nums.end());
  //     return (*it);
  //   }
  int repeatedNTimes(vector<int>& nums) {
    for (auto it = nums.begin(); it != nums.end() - 2; ++it) {
      if ((*it) == (*(it + 1)) || (*it) == (*(it + 2))) return (*it);
    }
    return nums.back();
  }
};
// @lc code=end
