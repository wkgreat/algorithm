/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

#include <stack>
#include <utility>
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
  void recoverTree(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    TreeNode* pred = nullptr;

    while (!stk.empty() || root != nullptr) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      if (pred != nullptr && root->val < pred->val) {
        y = root;
        if (x == nullptr) {
          x = pred;
        } else
          break;
      }
      pred = root;
      root = root->right;
    }

    swap(x->val, y->val);
  }
};
// @lc code=end

// 先中序遍历在恢复版本
class Solution1 {
 public:
  void flatten(TreeNode* root, vector<int>& nodes) {
    if (root == nullptr) {
      return;
    }
    if (root->left) {
      flatten(root->left, nodes);
    }
    nodes.push_back(root->val);
    if (root->right) {
      flatten(root->right, nodes);
    }
  }
  pair<int, int> findnodes(vector<int>& nodes) {
    int x, y;
    for (int i = 0; i < nodes.size() - 1; ++i) {
      if (nodes[i] > nodes[i + 1]) {
        x = nodes[i];
        break;
      }
    }
    for (int i = nodes.size() - 1; i > 0; --i) {
      if (nodes[i] < nodes[i - 1]) {
        y = nodes[i];
        break;
      }
    }
    return {x, y};
  }
  void recover(TreeNode* root, int x, int y) {
    if (root == nullptr) {
      return;
    }
    recover(root->left, x, y);
    if (root->val == x) {
      root->val = y;
    } else if (root->val == y) {
      root->val = x;
    }
    recover(root->right, x, y);
  }
  void recoverTree(TreeNode* root) {
    vector<int> nodes(0);
    flatten(root, nodes);
    pair<int, int> p = findnodes(nodes);
    int x = p.first;
    int y = p.second;
    recover(root, x, y);
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->left->right = new TreeNode(2);
  s.recoverTree(root);
  return 0;
}
