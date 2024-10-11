/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int moveRight(vector<int>& nums, int i) {
    i++;
    while (i < nums.size() && nums[i] == nums[i - 1]) i++;
    return i;
  }
  int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int i = 0;
    int n = 0;
    int d;
    for (int i = 0; i < nums.size(); i = moveRight(nums, i)) {
      for (int j = i + 1; j < nums.size(); j = moveRight(nums, j)) {
        d = nums[j] - nums[i];
        if (d < k) {
          continue;
        } else if (d == k) {
          n++;
          break;
        } else {
          break;
        }
      }
    }
    return n;
  }
};
// @lc code=end
int main() {
  vector<int> nums{3, 1, 4, 1, 5};
  Solution s;
  int r = s.findPairs(nums, 2);
  return 0;
}
