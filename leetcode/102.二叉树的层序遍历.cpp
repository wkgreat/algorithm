/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include <cmath>
#include <queue>
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int i = 0;
    int pl = -1;
    vector<vector<int>> r(0);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node == nullptr) {
        i++;
        continue;
      } else {
        int level = static_cast<int>(log2(i + 1));
        q.push(node->left);
        q.push(node->right);
        if (level != pl) {
          r.push_back({});
        }
        r.back().push_back(node->val);
        pl = level;
        i++;
      }
    }
    return r;
  }
};
// @lc code=end
