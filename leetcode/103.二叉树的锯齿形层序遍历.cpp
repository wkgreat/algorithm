/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

#include <deque>
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    deque<TreeNode*> q;
    vector<vector<int>> r(0);
    if (!root) {
      return r;
    }
    q.push_back(root);
    bool isInverse = false;
    while (!q.empty()) {
      r.push_back({});
      int qsize = q.size();
      for (int i = 0; i < qsize; ++i) {
        if (!isInverse) {
          TreeNode* node = q.front();
          r.back().push_back(node->val);
          q.pop_front();
          if (node->left) {
            q.push_back(node->left);
          }
          if (node->right) {
            q.push_back(node->right);
          }
        } else {
          TreeNode* node = q.back();
          r.back().push_back(node->val);
          q.pop_back();
          if (node->right) {
            q.push_front(node->right);
          }
          if (node->left) {
            q.push_front(node->left);
          }
        }
      }
      isInverse = !isInverse;
    }
    return r;
  }
};
// @lc code=end

int main() {
  Solution s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  s.zigzagLevelOrder(root);
  return 0;
}
