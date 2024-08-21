/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  // 搜索最左值
  int lbsearch(vector<int>& nums, int target, int L, int R) {
    if (L > R) {
      return -1;
    }
    int M = (L + R) / 2;
    if (L < M && nums[M - 1] >= target) {  // 优先搜索左段
      return lbsearch(nums, target, L, M - 1);
    }
    if (nums[M] == target) {  // 如果左段没有，则比较中值
      return M;
    }
    if (target > nums[M]) {  // 如果中值没有，则最后搜索右段
      return lbsearch(nums, target, M + 1, R);
    }
    return -1;
  }
  // 搜索最右值
  int rbsearch(vector<int>& nums, int target, int L, int R) {
    if (L > R) {
      return -1;
    }
    int M = (L + R) / 2;
    if (R > M && nums[M + 1] <= target) {  // 优先搜索右段
      return rbsearch(nums, target, M + 1, R);
    }
    if (nums[M] == target) {  // 如果右段没有，则比较中值
      return M;
    }
    if (target < nums[M]) {  // 如果中值没有，则判断左段
      return rbsearch(nums, target, L, M - 1);
    }
    return -1;
  }
  vector<int> searchRange(vector<int>& nums, int target) {
    const int N = nums.size();
    if (N == 0) {
      vector<int> r{-1, -1};
      return r;
    }
    int lr = lbsearch(nums, target, 0, N - 1);
    int rr = rbsearch(nums, target, 0, N - 1);
    vector<int> r{lr, rr};
    return r;
  }
};
// @lc code=end
