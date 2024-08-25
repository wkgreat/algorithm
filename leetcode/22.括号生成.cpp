/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  void backtrace(vector<string>& result, stack<char>& status, string& combination, int nl, int nr,
                 int n) {
    if (nl >= n && nr >= n) {           // 如果已经到底（所有框号都被取完）
      if (status.size() == 0) {         // 如果栈为空，说明符合条件
        result.push_back(combination);  // 将该组合推入结果
      }
    }
    if (nl < n) {  // 还可以选择左括号
      // 更新至下一状态
      status.push('(');
      combination.push_back('(');
      // 回溯下一状态
      backtrace(result, status, combination, nl + 1, nr, n);
      // 还原状态
      combination.pop_back();
      status.pop();
    }
    if (nr < n) {  // 还可以选择右括号
      if (status.size() > 0 &&
          status.top() == '(') {  // 栈顶为左括号，为了防止将右括号推入栈底，右括号在栈底无解
        // 更新至下一状态
        status.pop();  // 栈顶为左括号，与要压入的右括号抵消，所以直接弹出栈顶左括号
        combination.push_back(')');
        // 回溯下一状态
        backtrace(result, status, combination, nl, nr + 1, n);
        // 还原状态
        combination.pop_back();
        status.push('(');
      }
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    stack<char> status;
    string combination;
    backtrace(result, status, combination, 0, 0, n);
    return result;
  }
};
// @lc code=end
