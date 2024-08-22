/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    const int N = nums.size();

    vector<int> dp(N, 10E5);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
      for (int k = 1; k <= nums[i] && i + k < N; ++k) {
        dp[i + k] = min(dp[i + k], dp[i] + 1);
      }
    }
    return dp[N - 1];
  }
};
// @lc code=end
