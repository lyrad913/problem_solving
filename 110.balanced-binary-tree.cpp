/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// Definition for a binary tree node.
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
  int getHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
  }
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    int diff = abs(leftHeight - rightHeight);
    return diff <= 1 && isBalanced(root->left) && isBalanced(root->right);
  }
};
// @lc code=end
