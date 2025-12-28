/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 주어진 시간 동안 최대로 이익을 얻을 수 있는 "최대" 두 개의 겹치지 않는 이벤트
// 선택 문제 풀이1 일단 잘 모르겠으니.. 완전 탐색 O(n^2) 이고 10^10승이니까 잘
// 하면 간당간당하게 걸칠지도
// -> TLE. 최적화 방법.. 중복되는 부분문제가 없어 동적 계획법은 모르겟음

// 풀이2
// 한 개로 최대거나, 혹은 두 개의 합이 최대거나. 인데 한 개로 최대인 건 O(n)으로
// 구할 수 있음. 두 개의 합의 최대를 빠르게 구하는 방법만 알면 됨. 탐색 범위를
// 줄이려면..  시작시간 별 연결리스트를 만들고 건너뛰는 건 어떨까.
// -> 10^9 크기의 배열은 좀 부담스러운데.
// 가치를 기준으로 정렬하고, 가능한 제일 큰 거 두 개 합이랑 한개랑 비교하면 되지
// 않을까. 계속 겹치는 경우에는 break문이 동작하지 않음. -> TLE

// 힌트1 : 시점을 기준으로 정렬하는 건 어떤 도움이 될까? -> 모르겠는디요...
bool compare(const vector<int>& event1, const vector<int>& event2) {
  return event1[2] > event2[2];
}
bool compare2(const vector<int>& event1, int val) { return event1[0] <= val; }

class Solution {
 public:
  // int solution(vector<vector<int>>& events){
  //     int ret = 0;
  //     for(auto it1 = events.begin(); it1 != events.end(); ++it1){
  //         auto event1 = *it1;
  //         int temp_ret = event1[2];
  //         ret = max(ret, temp_ret);
  //         for(auto it2 = it1 + 1; it2 != events.end(); ++it2){
  //             auto event2 = *it2;
  //             if(event2[1] < event1[0] || event1[1] < event2[0]){
  //                 ret = max(ret, temp_ret+event2[2]);
  //             }
  //         }
  //     }
  //     return ret;
  // }

  //   int solution(vector<vector<int>>& events) {
  //     int ret = 0;
  //     for (auto event : events) ret = max(ret, event[2]);

  //     sort(events.begin(), events.end(), compare);

  //     int temp = 0;
  //     for (auto it1 = events.begin(); it1 != events.end(); ++it1) {
  //       for (auto it2 = it1 + 1; it2 != events.end(); ++it2) {
  //         if ((*it1)[1] < (*it2)[0] || (*it2)[1] < (*it1)[0]) {
  //           temp = max(temp, (*it1)[2] + (*it2)[2]);
  //           break;
  //         }
  //       }
  //     }
  //     return max(ret, temp);
  //   }

  int solution(vector<vector<int>>& events, int idx, int cnt,
               vector<vector<int>>& cache) {
    // base case
    if (cnt == 2 || idx >= events.size()) return 0;

    auto& ret = cache[idx][cnt];
    if (ret != -1) return ret;

    // 1. 현재 이벤트 안씀.
    int candi1 = solution(events, idx + 1, cnt, cache);

    // 2. 현재 이벤트를 사용할 경우에는 다음 이벤트의 위치를 이진탐색으로 사용
    auto next_idx = lower_bound(events.begin() + idx + 1, events.end(),
                                events[idx][1], compare2);
    int candi2 = events[idx][2] +
                 solution(events, next_idx - events.begin(), cnt + 1, cache);

    return ret = max(candi1, candi2);
  }

  int maxTwoEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());
    vector<vector<int>> cache(events.size(), vector<int>(3, -1));
    return solution(events, 0, 0, cache);
  }
};
// @lc code=end
