/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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

#include <bits/stdc++.h>

using namespace std;

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
class Solution {
 public:
  // 10^4 * 5 * 10^4 는 int 의 범위를 안넘어가기 때문에 안전할 듯?
  vector<int> partial_sums;
  // 해당 노드를 루트로 하는 서브트리의 합을 반환한다.
  int dfs(TreeNode* root) {
    if (root == nullptr) return 0;

    int partial_sum = root->val + dfs(root->left) + dfs(root->right);
    partial_sums.push_back(partial_sum);
    return partial_sum;
  }

  int maxProduct(TreeNode* root) {
    int sum = dfs(root);
    // cout << sum << endl;

    int min_diff = INT_MAX;
    int partial_sum;
    for (auto s : partial_sums) {
      int cand = abs(sum - 2 * s);
      if (min_diff > cand) {
        min_diff = cand;
        partial_sum = s;
      }
    }

    int mod = 1e9 + 7;

    // 곱할 때 오버플로우 조심
    return (int)((long long)((sum - partial_sum) % mod) *
                 (long long)(partial_sum % mod) % mod);
  }
};
// @lc code=end
