/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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

class Solution {
 public:
  unordered_map<TreeNode*, int> depth;
  int max_depth = -1;
  void cal_depth_of_node(TreeNode* root, TreeNode* parent = nullptr) {
    if (root) {
      depth[root] = parent == nullptr ? 0 : depth[parent] + 1;
      max_depth = max(max_depth, depth[root]);
      cal_depth_of_node(root->left, root);
      cal_depth_of_node(root->right, root);
    }
  }

  TreeNode* answer(TreeNode* root) {
    if (!root || depth[root] == max_depth) return root;

    auto left = answer(root->left);
    auto right = answer(root->right);

    if (left && right) return root;
    return left ? left : right;
  }
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    cal_depth_of_node(root);
    return answer(root);
  }
};
// @lc code=end
