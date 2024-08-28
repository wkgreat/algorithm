/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

#include <vector>

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
  vector<TreeNode*> generate(int L, int R) {
    vector<TreeNode*> res(0);
    if (L > R) {
      res.push_back(nullptr);
      return res;
    } else {
      for (int M = L; M <= R; ++M) {                // 遍历中间节点
        vector<TreeNode*> ls = generate(L, M - 1);  // 左子树
        vector<TreeNode*> rs = generate(M + 1, R);  // 右子树
        for (TreeNode* l : ls) {
          for (TreeNode* r : rs) {
            TreeNode* node = new TreeNode(M);
            node->left = l;
            node->right = r;
            res.push_back(node);
          }
        }
      }
      return res;
    }
  }

  vector<TreeNode*> generateTrees(int n) { return generate(1, n); }
};
// @lc code=end
