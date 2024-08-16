/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int rightMove(vector<int>& nums, int i) {
    int j = i + 1;
    while (j < nums.size() && nums[j] == nums[j - 1]) j++;
    return j;
  }
  int leftMove(vector<int>& nums, int i) {
    int j = i - 1;
    while (j >= 0 && nums[j] == nums[j + 1]) j--;
    return j;
  }
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> r;
    std::sort(nums.begin(), nums.end());
    const int N = nums.size();
    for (int a = 0; a < N - 3; a = rightMove(nums, a)) {
      if (a > 0 && nums[a] == nums[a - 1]) continue;
      for (int b = a + 1; b < N - 2; b = rightMove(nums, b)) {
        int c = b + 1;
        int d = N - 1;
        while (c < d) {
          long s = static_cast<long>(nums[a]) + nums[b] + nums[c] + nums[d] - target;
          if (s > 0) {
            d = leftMove(nums, d);
          } else if (s < 0) {
            c = rightMove(nums, c);
          } else {
            vector<int> v = {nums[a], nums[b], nums[c], nums[d]};
            r.push_back(std::move(v));
            d = leftMove(nums, d);
            c = rightMove(nums, c);
          }
        }
      }
    }
    return r;
  }
};
// @lc code=end
