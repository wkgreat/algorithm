/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  void rotate2(vector<vector<int>>& matrix, int L, int R, int U, int D) {
    if (L >= R || U >= D) {
      return;
    }
    int i = U;
    for (int j = L; j < R; ++j) {
      int si = i;
      int sj = j;
      int sv = matrix[si][sj];
      int ci = i;
      int cj = j;
      int pi = D - j + L;
      int pj = L;
      matrix[ci][cj] = matrix[pi][pj];
      ci = pi;
      cj = pj;
      pi = D;
      pj = R - j + L;
      matrix[ci][cj] = matrix[pi][pj];
      ci = pi;
      cj = pj;
      pi = U + j - L;
      pj = R;
      matrix[ci][cj] = matrix[pi][pj];
      matrix[pi][pj] = sv;
    }
    rotate2(matrix, L + 1, R - 1, U + 1, D - 1);
  }
  void rotate(vector<vector<int>>& matrix) {
    rotate2(matrix, 0, matrix.size() - 1, 0, matrix.size() - 1);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> v{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  s.rotate(v);
  return 0;
}
