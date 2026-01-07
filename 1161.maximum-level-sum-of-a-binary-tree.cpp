/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // level 별이니까 queue에다가 때려넣고 하면 되겠지 뭐.. 레벨 별 원소의 개수는
  // 2^{level - 1} 정도 인것만 해두면 될듯
  // 큐에 넣고 단계별로 생각하려니까 머리가 아픈데 그냥 벡터에 펼쳐두고
  // 계산하는게 편하겠음 아 뭐가 복잡하네.. nullptr이 모든 걸 복잡하게 함.
  // 원래는 nullptr이면 안넣어야하는데.. level을 알려면 어떻게 해야하나? 아하
  // 큐에 쌍으로 넣으면 되겠다.
  int maxLevelSum(TreeNode* root) {
    queue<pair<int, TreeNode*>> q;
    q.push(make_pair(1, root));

    int prev_level = 0;
    int level_sum = INT_MIN;
    int max_sum = INT_MIN;
    int ret = INT_MIN;
    while (!q.empty()) {
      auto tmp = q.front();
      q.pop();

      int cur_level = tmp.first;
      auto cur_node = tmp.second;

      if (cur_level != prev_level) {
        ret = max_sum < level_sum ? prev_level : ret;
        max_sum = max(max_sum, level_sum);
        level_sum = 0;
        prev_level = cur_level;
      }

      level_sum += cur_node->val;

      if (cur_node->right != nullptr)
        q.push(make_pair(cur_level + 1, cur_node->right));
      if (cur_node->left != nullptr)
        q.push(make_pair(cur_level + 1, cur_node->left));
    }

    if (max_sum < level_sum) {
      ret = prev_level;
    }

    return ret;
  }
};
// @lc code=end
