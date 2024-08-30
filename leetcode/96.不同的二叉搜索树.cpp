/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
 public:
  int cntTrees(int L, int R) {
    if (L >= R) {
      return 1;
    } else {
      int s = 0;
      for (int M = L; M <= R; ++M) {
        int lcnt = cntTrees(L, M - 1);
        int rcnt = cntTrees(M + 1, R);
        s += lcnt * rcnt;
      }
      return s;
    }
  }
  int numTrees(int n) { return cntTrees(1, n); }
};
// @lc code=end
