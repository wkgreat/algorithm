/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include <vector>

using namespace std;

// @lc code=start
/*
贪心法-官方
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};
// @lc code=end

/*
动态规划法-官方
定义状态
    dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润，（空仓）
    dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）（持有）

dp[i][0]=max{dp[i−1][0],dp[i−1][1]+prices[i]}
dp[i][1]=max{dp[i−1][1],dp[i−1][0]−prices[i]}
dp[0][0]=0，dp[0][1]=−prices[0]
*/
class Solution0_1 {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp[n][2];
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
  }
};

/*
动态规划法
每天三种操作：买入、卖出、持有、空仓
dp[i][买入] = max(dp[i-1][卖出],dp[i-1][空仓]) - price[i]
dp[i][卖出] = max(dp[i-1][持有],dp[i-1][买入]) + price[i]
dp[i][持有] = max(dp[i-1][持有],dp[i-1][买入])
dp[i][空仓] = max(dp[i-1][空仓],dp[i-1][卖出])

dp[0][买入] = -price[0]
dp[0][卖出] = 0
dp[0][持有] = -price[0]
dp[0][空仓] = 0
*/
class Solution1 {
 public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    if (N == 0) {
      return 0;
    }
    vector<vector<int>> dp(N, vector<int>(4, 0));
    dp[0][0] = -prices[0];
    dp[0][2] = -prices[0];
    for (int i = 1; i < N; ++i) {
      dp[i][0] = max(dp[i - 1][1], dp[i - 1][3]) - prices[i];
      dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + prices[i];
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][0]);
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][1]);
    }
    int r = dp[N - 1][0];
    r = max(r, dp[N - 1][1]);
    r = max(r, dp[N - 1][2]);
    r = max(r, dp[N - 1][3]);
    return r;
  }
};
