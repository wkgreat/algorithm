/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int L = 1;
    int R = 1;
    int N = nums.size();
    while (R < N) {
      if (nums[R] == nums[R - 1]) {
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
