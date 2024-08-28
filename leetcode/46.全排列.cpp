/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<bool>& mask,
                 vector<int>& comb) {
    if (comb.size() >= nums.size()) {
      res.push_back(comb);
    } else {
      for (int i = 0; i < nums.size(); ++i) {
        if (!mask[i]) {
          mask[i] = true;
          comb.push_back(nums[i]);
          backtrack(res, nums, mask, comb);
          mask[i] = false;
          comb.pop_back();
        }
      }
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> mask(nums.size(), false);
    vector<int> comb(0);
    vector<vector<int>> res(0);
    backtrack(res, nums, mask, comb);
    return res;
  }
};
// @lc code=end
