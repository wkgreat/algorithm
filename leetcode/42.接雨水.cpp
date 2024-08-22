/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    const int N = height.size();
    vector<int> maxL(N, 0);
    vector<int> maxR(N, 0);
    int m = 0;
    for (int i = 1; i < N; ++i) {
      if (height[i - 1] > m) {
        m = height[i - 1];
      }
      maxL[i] = m;
    }
    m = 0;
    for (int i = N - 2; i >= 0; --i) {
      if (height[i + 1] > m) {
        m = height[i + 1];
      }
      maxR[i] = m;
    }
    int s = 0;
    for (int i = 0; i < N; ++i) {
      int k = min(maxL[i], maxR[i]);
      if (k > height[i]) {
        s += (k - height[i]);
      }
    }
    return s;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int r = s.trap(v);
  return 0;
}
