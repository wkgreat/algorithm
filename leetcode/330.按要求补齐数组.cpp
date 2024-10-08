/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    int patches = 0;
    long long x = 1;
    int length = nums.size(), index = 0;
    while (x <= n) {
      if (index < length && nums[index] <= x) {
        x += nums[index];
        index++;
      } else {
        x <<= 1;  // x*=2
        patches++;
      }
    }
    return patches;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums{1, 3};
  s.minPatches(nums, 6);
  return 0;
}
