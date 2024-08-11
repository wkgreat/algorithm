/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 * dp[i][j] = min(dp[i-1][j]+v, dp[i][j-1]+v);
 * dp[i][j] = dp[i][j-1]+v if i==0
 * dp[i][j] = dp[i-1][j]+v if j==0
 * dp[i][j] = v; if i==0 && j==0
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (i == 0 && j == 0)
          continue;
        else if (i == 0)
          grid[i][j] = grid[i][j] + grid[i][j - 1];
        else if (j == 0)
          grid[i][j] = grid[i][j] + grid[i - 1][j];
        else
          grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
      }
    }
    return grid[grid.size() - 1][grid[0].size() - 1];
  }
};
// @lc code=end
