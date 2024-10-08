/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

#include <bits/stdc++.h>
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
/*
    官方题解
*/
class Solution {
 private:
  int maxSum = INT_MIN;

 public:
  int maxGain(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }

    // 递归计算左右子节点的最大贡献值
    // 只有在最大贡献值大于 0 时，才会选取对应子节点
    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);

    // 以当前节点为根节点，节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
    int priceNewpath = node->val + leftGain + rightGain;

    // 更新答案
    maxSum = max(maxSum, priceNewpath);

    // 返回节点的最大贡献值
    // 从父节点到当前节点后，只能选择当前节点的左右一个分支
    return node->val + max(leftGain, rightGain);
  }

  int maxPathSum(TreeNode* root) {
    maxGain(root);
    return maxSum;
  }
};
// @lc code=end

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(1);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(1);
  Solution s;
  int r = s.maxPathSum(root);
  cout << r << endl;
  return 0;
}
