#include <iostream>
#include <stack>
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

// 递归版本
void inorder_recursion(TreeNode* root, vector<int>& vals) {
  if (root == nullptr) {
    return;
  }
  if (root->left) {
    inorder_recursion(root->left, vals);
  }
  vals.push_back(root->val);
  if (root->right) {
    inorder_recursion(root->right, vals);
  }
}

// 非递归版本
void inorder_stack(TreeNode* root, vector<int>& vals) {
  stack<TreeNode*> stk;
  while (!stk.empty() || root != nullptr) {
    while (root) {
      stk.push(root);
      root = root->left;
    }
    TreeNode* cur = stk.top();
    stk.pop();
    vals.push_back(cur->val);
    root = cur->right;
  }
}

int main() {
  /*
       4
     2   6
    1 3 5 7
  */
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right = new TreeNode(6);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);

  vector<int> vals(0);
  inorder_recursion(root, vals);
  cout << "中序遍历递归版本结果: " << endl;
  for (int v : vals) {
    cout << v << "\t";
  }
  cout << endl;

  vals.clear();
  inorder_stack(root, vals);
  cout << "中序遍历非递归(迭代)版本结果: " << endl;
  for (int v : vals) {
    cout << v << "\t";
  }
  cout << endl;
  return 0;
}