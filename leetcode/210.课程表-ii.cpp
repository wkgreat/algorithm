/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, int> cntmap;
    vector<int> visited(numCourses, 0);
    for (int i = 0; i < numCourses; ++i) {
      cntmap[i] = 0;
    }
    for (const auto p : prerequisites) {
      cntmap[p[0]]++;
    }
    vector<int> r;
    while (true) {
      bool f = true;
      for (const auto pair : cntmap) {
        if (!visited[pair.first] && pair.second == 0) {
          r.push_back(pair.first);
          visited[pair.first] = 1;
          for (auto p : prerequisites) {
            if (p[1] == pair.first) {
              cntmap[p[0]]--;
            }
          }
          f = false;
          break;
        }
      }
      if (f) {
        break;
      }
    }
    if (r.size() == numCourses) {
      return r;
    } else {
      return {};
    }
  }
};
// @lc code=end
