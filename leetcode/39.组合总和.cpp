/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combination(vector<int>& candinates, int target, int L) {
    vector<vector<int>> res;
    for (int i = L; i < candinates.size(); ++i) {
      if (candinates[i] < target) {
        vector<vector<int>> r = combination(candinates, target - candinates[i], i);
        for (auto& v : r) {
          v.push_back(candinates[i]);
        }
        res.insert(res.end(), r.begin(), r.end());
      } else if (candinates[i] == target) {
        vector<int> r{candinates[i]};
        res.push_back(r);
      } else if (candinates[i] > target) {
        break;
      }
    }
    return res;
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> res = combination(candidates, target, 0);
    return res;
  }
};
// @lc code=end
