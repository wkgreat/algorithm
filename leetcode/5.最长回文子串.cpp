/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    // dp[i][j]: s[i..j]的回文长度
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

    // 单个字符回文长度为1
    for (int i = 0; i < s.size(); ++i) {
      dp[i][i] = 1;
    }
    // 迭代字符串长度
    for (int k = 1; k < s.size(); ++k) {
      // 迭代对应长度的子串
      for (int L = 0, R = L + k; R < s.size(); L++, R++) {
        if (s[L] != s[R]) {  // 如果该子串前后两个字符不同，则不是回文，回文长度为零
          dp[L][R] = 0;
        } else if (R == L + 1) {  // 如果该子串前后两字符相同，且无子子串
          dp[L][R] = 2;           // 则回文长度为2
        } else {
          if (dp[L + 1][R - 1] > 0) {  // 如果该子串前后两字符相同，且有子子串回文
            dp[L][R] = dp[L + 1][R - 1] + 2;  // 回文长度=子子串回文长度+2
          } else {         // 如果该子串前后两字符相同，且有子子串不是回文
            dp[L][R] = 0;  // 回文长度=0
          }
        }
      }
    }

    // 遍历，找到长度最大的回文
    int maxLen = 0;
    int maxL, maxR;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i; j < s.size(); ++j) {
        if (dp[i][j] > maxLen) {
          maxLen = dp[i][j];
          maxL = i;
          maxR = j;
        }
      }
    }
    return s.substr(maxL, maxR - maxL + 1);
  }
};
// @lc code=end
