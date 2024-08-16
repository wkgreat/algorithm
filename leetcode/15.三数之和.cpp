/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
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
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> r;
    const int n = nums.size();
    int s;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2 && nums[i] <= 0; i = rightMove(nums, i)) {
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        s = nums[i] + nums[j] + nums[k];
        if (s < 0) {
          j = rightMove(nums, j);
        } else if (s > 0) {
          k = leftMove(nums, k);
        } else {
          vector<int> v{nums[i], nums[j], nums[k]};
          r.push_back(std::move(v));
          k = leftMove(nums, k);
          j = rightMove(nums, j);
        }
      }
    }
    return r;
  }
};
// @lc code=end
