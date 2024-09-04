/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    vector<int> status(nums.size(), 0);
    status[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (status[i]) {
        for (int k = 1; k <= nums[i]; ++k) {
          if (i + k < nums.size()) {
            status[i + k] = 1;
          }
        }
      }
    }
    return status[nums.size() - 1];
  }
};
// @lc code=end
