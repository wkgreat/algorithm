/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    const int N = nums.size();
    if (N == 1) {
      return;
    }
    for (int i = N - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        int minv = nums[i + 1];
        int mini = i + 1;
        for (int j = i + 2; j < N; ++j) {
          if (nums[j] > nums[i] && nums[j] < minv) {
            minv = nums[j];
            mini = j;
          }
        }
        int t = nums[i];
        nums[i] = nums[mini];
        nums[mini] = t;
        std::sort(nums.begin() + i + 1, nums.end());
        return;
      }
    }
    std::sort(nums.begin(), nums.end());
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> vec{2, 3, 1};
  return 0;
}
