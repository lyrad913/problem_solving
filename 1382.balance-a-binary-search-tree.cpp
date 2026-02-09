/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
  TreeNode* makeBalancedBST(vector<int>& v, int begin, int end) {
    if (begin > end) return nullptr;
    int mid = (begin + end) / 2;

    TreeNode* root = new TreeNode(v[mid], makeBalancedBST(v, begin, mid - 1),
                                  makeBalancedBST(v, mid + 1, end));

    return root;
  }
  void inorder(TreeNode* root, vector<int>& ret) {
    if (!root) return;
    inorder(root->left, ret);
    ret.push_back(root->val);
    inorder(root->right, ret);
  }
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodeList;
    inorder(root, nodeList);
    int n = nodeList.size();
    return makeBalancedBST(nodeList, 0, n - 1);
  }
};
// @lc code=end
