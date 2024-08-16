/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    const int N = nums.size();
    int mind = 10E5;
    int mins = 10E5;
    for (int i = 0; i < N - 2; ++i) {
      int j = i + 1;
      int k = N - 1;
      while (j < k) {
        int s = nums[i] + nums[j] + nums[k];
        int d = s - target;
        if (d == 0) {
          return s;
        }
        if (abs(d) < mind) {
          mind = abs(d);
          mins = s;
        }
        if (d > 0) {
          k--;
        } else if (d < 0) {
          j++;
        }
      }
    }
    return mins;
  }
};
// @lc code=end
