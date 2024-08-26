/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool backtrace(vector<vector<char>>& board, int i, int j) {
    if (i >= 9) {
      return true;
    } else if (board[i][j] != '.') {
      if (j >= 9) {
        return backtrace(board, i + 1, 0);
      } else {
        return backtrace(board, i, j + 1);
      }
    } else {
      set<char> remain{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
      for (int k = 0; k < 9; ++k) {
        remain.erase(board[i][k]);
        remain.erase(board[k][j]);
        remain.erase(board[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3]);
      }
      if (remain.size() == 0) {
        return false;
      }
      for (char c : remain) {
        board[i][j] = c;
        bool b;
        if (j >= 8) {
          b = backtrace(board, i + 1, 0);
        } else {
          b = backtrace(board, i, j + 1);
        }
        if (b) {
          return true;
        }
        board[i][j] = '.';
      }
      return false;
    }
  }
  void solveSudoku(vector<vector<char>>& board) { backtrace(board, 0, 0); }
};
// @lc code=end
int main() {
  Solution s;
  vector<vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  s.solveSudoku(board);
  return 0;
}
