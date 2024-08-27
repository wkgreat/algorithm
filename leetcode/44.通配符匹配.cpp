/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= p.size(); ++j) {  // s字符串为空的情况下
      if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 1];
      } else {  // 如果s为空，只要p包含字母或者问号？则就无法匹配
        dp[0][j] = false;
      }
    }
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= p.size(); ++j) {
        if (p[j - 1] == '*') {  // p为星号* 只要dp[k<=i][j-1]中包含true就行
          for (int k = 0; k <= i; ++k) {
            if (dp[k][j - 1]) {
              dp[i][j] = true;
              break;
            }
          }
        } else if (p[j - 1] == '?') {  // p当前为问号
          dp[i][j] = dp[i - 1][j - 1];
        } else {  // p当前为普通字符
          dp[i][j] = (s[i - 1] == p[j - 1] && dp[i - 1][j - 1]);
        }
      }
    }

    return dp[s.size()][p.size()];
  }
};
// @lc code=end

int main() {
  Solution s;
  bool r = s.isMatch("adceb", "*a*b");
  return 0;
}
