/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */

#include <bits/stdc++.h>

using namespace std;

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

class Solution {
 public:
  bool isLeaf(TreeNode* root) {
    return (root->left == nullptr) && (root->right == nullptr);
  }
  int strToInt(const string& str) {
    int ret = 0;
    int base = 1;
    for (auto it = str.rbegin(); it != str.rend(); ++it, base *= 2) {
      ret += base * ((*it) == '1' ? 1 : 0);
    }
    return ret;
  }
  string valToStr(int n) { return n == 1 ? "1" : "0"; }
  int sumRootToLeaf(TreeNode* root, string str) {
    str += valToStr(root->val);
    // base case
    if (isLeaf(root)) return strToInt(str);

    int leftSum = 0, rightSum = 0;
    if (root->left) leftSum = sumRootToLeaf(root->left, str);
    if (root->right) rightSum = sumRootToLeaf(root->right, str);

    return leftSum + rightSum;
  }
  int sumRootToLeaf(TreeNode* root) { return sumRootToLeaf(root, ""); }
};
// @lc code=end
