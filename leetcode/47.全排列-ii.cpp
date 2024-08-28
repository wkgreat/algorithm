/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <algorithm>
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
        if (mask[i] || (i > 0 && nums[i] == nums[i - 1] && !mask[i - 1])) {
          continue;
        }
        mask[i] = true;
        comb.push_back(nums[i]);
        backtrack(res, nums, mask, comb);
        comb.pop_back();
        mask[i] = false;
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res(0);
    vector<bool> mask(nums.size(), false);
    vector<int> comb(0);
    sort(nums.begin(), nums.end());
    backtrack(res, nums, mask, comb);
    return res;
  }
};
// @lc code=end
