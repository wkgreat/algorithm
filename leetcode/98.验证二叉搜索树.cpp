/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include <limits.h>
#include <cmath>

using namespace std;

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
  bool isValid(TreeNode* root, long minV, long maxV) {
    if (!root) {
      return true;
    }
    // 当前节点值是否符合要求
    if (root->val <= minV || root->val >= maxV) {
      return false;
    }
    // 左子树是否要求 及 右子树是否符合要求
    return isValid(root->left, minV, min(static_cast<long>(root->val), maxV)) &&
           isValid(root->right, max(static_cast<long>(root->val), minV), maxV);
  }
  bool isValidBST(TreeNode* root) { return isValid(root, LONG_MIN, LONG_MAX); }
};
// @lc code=end

int main() {
  Solution s;
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  s.isValidBST(root);
  return 0;
}
