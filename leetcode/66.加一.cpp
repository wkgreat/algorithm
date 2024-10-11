/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int i = n - 1;
    while (i >= 0 && digits[i] == 9) {
      digits[i] = 0;
      i--;
    }
    if (i >= 0) {
      digits[i] += 1;
    } else {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};
// @lc code=end
