/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    // 结果只能在[1,N+1]范围之内
    const int N = nums.size();

    // 排除负数与0
    for (int i = 0; i < N; ++i) {
      if (nums[i] <= 0) {
        nums[i] = N + 1;
      }
    }
    for (int i = 0; i < N; ++i) {
      if (abs(nums[i]) <= N) {  // 当前数在[1,N]范围之内，取绝对值是因为该值所在索引位置可能被标记
        if (nums[abs(nums[i]) - 1] > 0) {  // 如果该位置没有被标记过
          nums[abs(nums[i]) - 1] *= -1;    // 标记
        }
      }
    }

    // 第一个未被标记的索引值+1为结果
    for (int i = 0; i < N; ++i) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }
    // 否则N+1为结果
    return N + 1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> v{7, 8, 9, 11, 12};
  int r = s.firstMissingPositive(v);
  return 0;
}
