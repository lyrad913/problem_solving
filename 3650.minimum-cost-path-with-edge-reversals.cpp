/*
 * @lc app=leetcode id=3650 lang=cpp
 *
 * [3650] Minimum Cost Path with Edge Reversals
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minCost(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> graph(n);

    for (const auto& edge : edges) {
      int from = edge[0], to = edge[1], weight = edge[2];

      graph[from].push_back(make_pair(to, weight));
      graph[to].push_back(make_pair(from, 2 * weight));
    }
    vector<int> dist(n, 1e8 + 1);
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 0));
    dist[0] = 0;

    while (!pq.empty()) {
      int here_dist = -pq.top().first;
      int here = pq.top().second;
      pq.pop();

      if (here == n - 1) return dist[here];
      if (visited[here]) continue;
      visited[here] = true;
      for (const auto& e : graph[here]) {
        int there = e.first;
        int there_dist = e.second + here_dist;
        if (there_dist < dist[there]) {
          dist[there] = there_dist;
          pq.push(make_pair(-dist[there], there));
        }
      }
    }

    return -1;
  }
};
// @lc code=end
