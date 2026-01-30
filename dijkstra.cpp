#include <bits/stdc++.h>

using namespace std;

class Solution {
  using PII = pair<int, int>;

 public:
  int minCost(int n, vector<vector<int>>& edges) {
    vector<vector<PII>> g(n);
    for (auto& e : edges) {
      int x = e[0], y = e[1], w = e[2];
      g[x].emplace_back(y, w);
      g[y].emplace_back(x, 2 * w);
    }

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<PII> pq;
    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
      int here = pq.top().second;
      pq.pop();
      if (here == n - 1) {
        return dist[here];
      }
      // only the first time unloading requires relaxing other points
      if (visited[here]) {
        continue;
      }
      visited[here] = true;

      for (const auto& [there, weight] : g[here]) {
        if (dist[here] + weight < dist[there]) {
          dist[there] = dist[here] + weight;
          pq.emplace(-dist[there], there);
        }
      }
    }
    return -1;
  }
};