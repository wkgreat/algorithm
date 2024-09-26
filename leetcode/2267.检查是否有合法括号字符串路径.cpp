/*
 * @lc app=leetcode.cn id=2267 lang=cpp
 *
 * [2267] 检查是否有合法括号字符串路径
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
/*
DFS法+剪数字优化，第三方题解
https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/solutions/1477302/tian-jia-zhuang-tai-hou-dfscpythonjavago-f287/?source=vscode
*/
class Solution {
 public:
  bool hasValidPath(vector<vector<char>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    if ((m + n) % 2 == 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;  // 剪枝
    // vector[m][n][(m + n + 1) / 2]
    vector<vector<vector<bool>>> vis(m, vector(n, vector((m + n + 1) / 2, false)));
    function<bool(int, int, int)> dfs = [&](int x, int y, int c) -> bool {
      if (c > m - x + n - y - 1) return false;  // 剪枝：即使后面都是 ')' 也不能将 c 减为 0
      if (x == m - 1 && y == n - 1) return c == 1;  // 终点一定是 ')'
      if (vis[x][y][c]) return false;               // 重复访问
      vis[x][y][c] = true;
      c += grid[x][y] == '(' ? 1 : -1;
      return c >= 0 &&
             (x < m - 1 && dfs(x + 1, y, c) || y < n - 1 && dfs(x, y + 1, c));  // 往下或者往右
    };
    return dfs(0, 0, 0);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<char>> grid{{'(', '(', '('}, {')', '(', ')'}, {'(', '(', ')'}, {'(', '(', ')'}};
  bool b = s.hasValidPath(grid);
  return 0;
}

/*
回溯法，计算左右括号个数，超时
当nl > len(path)/2 || nr > len(path)/2 || nr > nl 时肯定无法匹配，返回false
匹配成功条件，遍历到最后一个格子且nr==nl
*/
class Solution1 {
 public:
  bool backtrack(vector<vector<char>>& grid, int& nl, int& nr, int i, int j, int R, int C) {
    if (i >= R || j >= C) {
      return false;
    }
    if (grid[i][j] == '(') {
      nl++;
    } else {
      nr++;
    }
    bool b;
    if (nl > (R + C - 1) / 2 || nr > (R + C - 1) / 2 || nr > nl) {
      b = false;
    } else if (i == R - 1 && j == C - 1) {
      if (nl == nr) {
        b = true;
      } else {
        b = false;
      }
    } else {
      bool b1 = backtrack(grid, nl, nr, i + 1, j, R, C);
      if (b1) {
        b = b1;
      } else {
        bool b2 = backtrack(grid, nl, nr, i, j + 1, R, C);
        b = b2;
      }
    }
    if (grid[i][j] == '(') {
      nl--;
    } else {
      nr--;
    }
    return b;
  }
  bool hasValidPath(vector<vector<char>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
    int nl = 0;
    int nr = 0;
    return backtrack(grid, nl, nr, 0, 0, R, C);
  }
};