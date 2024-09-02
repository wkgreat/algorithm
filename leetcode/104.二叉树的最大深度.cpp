/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int max(int a, int b) { return a > b ? a : b; }
  int maxDepthRec(TreeNode* root, int d, int maxd) {
    if (!root) {
      return maxd;
    }
    if (d > maxd) {
      maxd = d;
    }
    if (root->left) {
      maxd = max(maxd, maxDepthRec(root->left, d + 1, maxd));
    }
    if (root->right) {
      maxd = max(maxd, maxDepthRec(root->right, d + 1, maxd));
    }
    return maxd;
  }
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return maxDepthRec(root, 1, 1);
  }
};
// @lc code=end
