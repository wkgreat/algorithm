/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int bsearch(vector<int>& nums, int target, int L, int R) {
    if (L > R) {  // 如果找不到目标值，则最终插入位置就是L
      return L;
    }
    int M = (L + R) / 2;
    int V = nums[M];
    if (target < V) {  // 如果目标值小于中值，则搜索左段
      return bsearch(nums, target, L, M - 1);
    }
    if (target > V) {  // 如果目标值大于中值，则搜索右段
      return bsearch(nums, target, M + 1, R);
    }
    if (target == V) {                  // 如果目标值等于中值，则要返回最左值
      if (L < M && nums[M - 1] == V) {  // 左段存在最左值，搜索左段
        return bsearch(nums, target, L, M - 1);
      } else {  // 左段不存储最左值，则返回中值索引
        return M;
      }
    }
    return -1;
  }
  int searchInsert(vector<int>& nums, int target) {
    return bsearch(nums, target, 0, nums.size() - 1);
  }
};
// @lc code=end
