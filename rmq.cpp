#include <bits/stdc++.h>
using namespace std;

class RMQ {
  // 구간트리에 주어진 배열의 길이
  int n;
  // 각 구간의 최소치
  vector<int> range_min;

  RMQ(const vector<int>& array) {
    n = array.size();
    range_min.resize(4 * n);
    init(array, 0, n - 1);
  }

  // =======================================================================

  // O(n) : 트리의 노드가 구간 최소 원소를 갖도록 한다.
  int init(const vector<int>& array, int left, int right, int node) {
    if (left == right) return range_min[node] = array[left];

    int mid = (left + right) / 2;
    int leftMin = init(array, left, mid, 2 * node);
    int rightMin = init(array, mid + 1, right 2 * node + 1);
    return range_min[node] = min(leftMin, rightMin);
  }

  // =======================================================================

  // 사용자는 내부 구현을 알 필요가 없다
  int query(int left, int right) { return query(left, right, 1, 0, n - 1); }

  // node가 표현하는 범위[nodeLeft, nodeRight]와 찾고자 하는 범위[left, right]의
  // 교집합의 최소 원소를 반환한다.
  // 걸쳐진 경우가 아니고서는 바로 반환되기 때문에 트리의 바닥까지 최대 두 번만
  // 탐색하므로 O(log n)
  int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    // 겹치지 않을 경우에는 매우 큰 수를 반환한다. min(~, ~)에서 걸러짐
    if (right < nodeLeft || nodeRight < left) return INT_MAX;

    // 노드가 탐색 구간을 완전히 포함할 경우
    if (left <= nodeLeft && nodeRight <= right) return range_min[node];

    // 걸쳐진 경우
    int mid = (nodeLeft + nodeRight) / 2;
    return min(query(left, right, 2 * node, nodeLeft, mid),
               query(left, right, 2 * node + 1, mid + 1, nodeRight));
  }

  // =======================================================================

  // 구간 트리의 갱신(배열의 값이 변한 경우)
  int update(int idx, int newValue) {
    return update(idx, newValue, 1, 0, n - 1);
  }

  // 바뀐 값을 포함하는 구간을 담당하는 노드는 O(log n)개 존재
  // 따라서 구간 트리를 새로 계산하는 것이 아닌 해당 노드들만 갱신
  int update(int idx, int newValue, int node, int nodeLeft, int nodeRight) {
    // 구간과 상관없는 경우
    if (idx < nodeLeft || nodeRight < idx) return range_min[node];

    // 트리의 리프까지 내려온 경우
    if (nodeLeft == nodeRight) return range_min[node] = newValue;

    int mid = (nodeLeft + nodeRight) / 2;
    return range_min[node] =
               min(update(idx, newValue, 2 * node, nodeLeft, mid),
                   update(idx, newValue, 2 * node + 1, mid + 1, nodeRight));
  }
};