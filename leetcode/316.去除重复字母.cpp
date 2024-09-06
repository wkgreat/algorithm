/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    vector<int> vis(26, 0);  // vis数组表示每个字母是否已经在结果字符串里了
    vector<int> num(26, 0);  // num数组为统计每个字母出现的次数
    string r;
    // 统计各字母的数量
    for (char c : s) {
      num[c - 'a'] += 1;
    }

    // 先推入第一个字母
    r.push_back(s[0]);
    vis[s[0] - 'a'] = 1;
    num[s[0] - 'a'] -= 1;

    for (int i = 1; i < s.size(); ++i) {
      char c = s[i];        // 当前字母
      if (!vis[c - 'a']) {  // 当前字母没出现过
        // 上个已经推入的字母是否比当前字母大（保证字典序最小）
        // 且后面还有该字母（每个字母出现次数有且只有一个）
        while (!r.empty() && r.back() > c && num[r.back() - 'a'] > 0) {
          // 删除上个推入的字母
          vis[r.back() - 'a'] = 0;
          r.pop_back();
        }
        // 推入当前字母
        r.push_back(c);
        vis[c - 'a'] = 1;
      }
      num[c - 'a'] -= 1;  // 当前字母出现，说明该字母在后续出现次数减1
    }
    return r;
  }
};
// @lc code=end

int main() {
  Solution s;
  string r = s.removeDuplicateLetters("cbacdcbc");
  return 0;
}
