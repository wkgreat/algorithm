/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, int> cntmap;
    vector<int> visited(numCourses, 0);
    for (int i = 0; i < numCourses; ++i) {
      cntmap[i] = 0;
    }
    for (const vector<int> pair : prerequisites) {
      cntmap[pair[0]]++;
    }
    while (true) {
      bool f = true;
      for (auto pair : cntmap) {
        if (!visited[pair.first] && pair.second == 0) {
          for (vector<int>& p : prerequisites) {
            if (p[1] == pair.first) {
              cntmap[p[0]]--;
            }
          }
          f = false;
          visited[pair.first] = 1;
        }
      }
      if (f) {
        break;
      }
    }
    for (auto pair : cntmap) {
      if (pair.second > 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> prerequisites{{1, 0}};
  s.canFinish(2, prerequisites);
  return 0;
}
