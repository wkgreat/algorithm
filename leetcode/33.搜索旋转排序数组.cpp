/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int bsearch(vector<int>& nums, int target, int L, int R) {
    if (L > R) {
      return -1;
    }
    int M = (L + R) / 2;
    int V = nums[M];
    if (V == target) {
      return M;
    } else if (target < V) {
      if (nums[L] < V || (L < M && nums[M - 1] < V)) {
        int r = bsearch(nums, target, L, M - 1);
        if (r != -1) {
          return r;
        }
      }
      if (nums[R] < V || (R > M && nums[M + 1] < V)) {
        int r = bsearch(nums, target, M + 1, R);
        if (r != -1) {
          return r;
        }
      }
    } else if (target > V) {
      if (nums[L] > V || (L < M && nums[M - 1] > V)) {
        int r = bsearch(nums, target, L, M - 1);
        if (r != -1) {
          return r;
        }
      }
      if (nums[R] > V || (R > M && nums[M + 1] > V)) {
        int r = bsearch(nums, target, M + 1, R);
        if (r != -1) {
          return r;
        }
      }
    }
    return -1;
  }
  int search(vector<int>& nums, int target) { return bsearch(nums, target, 0, nums.size() - 1); }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> v{1, 3};
  int r = s.search(v, 3);
  return 0;
}
