/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int L = 0;
    int R = 0;
    int N = nums.size();
    while (R < N) {
      if (nums[R] == val) {
        R++;
      } else {
        nums[L] = nums[R];
        L++;
        R++;
      }
    }
    return L;
  }
};
// @lc code=end
