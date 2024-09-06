/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = max(candies[i], candies[i - 1] + 1);
      }
    }
    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        candies[i] = max(candies[i], candies[i + 1] + 1);
      }
    }
    return accumulate(candies.begin(), candies.end(), 0);
  }
};
// @lc code=end
