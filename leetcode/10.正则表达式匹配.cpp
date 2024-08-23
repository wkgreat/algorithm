/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, 0));

    if (s.size() == 0) {
      if (p.size() == 0 || p == ".*") {
        return true;
      }
    }
    dp[0][0] = 1;

    for (int i = 0; i <= s.size(); ++i) {
      for (int j = 1; j <= p.size(); ++j) {
        if (i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {  // p当前为普通字符或点
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {  // p当前为星号*
          bool b1 = ((i >= 1 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) && dp[i - 1][j]);
          bool b2 = dp[i][j - 2];
          dp[i][j] = b1 || b2;
        } else {  // 其他情况不匹配
          dp[i][j] = 0;
        }
      }
    }
    return dp[s.size()][p.size()];
  }
};
// @lc code=end

int main() {
  Solution s;
  s.isMatch("aa", "a*");
  return 0;
}

/*

dp[i][j] = dp[i-1][j-1] when (s[i]=p[j] || p[j]='.')
dp[i][j] = dp[i][j-1] || (s[i] match p[j-1] && dp[i-1][j])  p[j] == '*'


*/
