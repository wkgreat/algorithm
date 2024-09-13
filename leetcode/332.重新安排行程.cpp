/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/*
官方题解 - Hierholzer 算法
欧拉图问题
*/
class OfficalSolution {
 public:
  unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

  vector<string> stk;

  void dfs(const string& curr) {
    while (vec.count(curr) && vec[curr].size() > 0) {
      string tmp = vec[curr].top();
      vec[curr].pop();
      dfs(move(tmp));
    }
    stk.emplace_back(curr);
  }

  vector<string> findItinerary(vector<vector<string>>& tickets) {
    for (auto& it : tickets) {
      vec[it[0]].emplace(it[1]);
    }
    dfs("JFK");

    reverse(stk.begin(), stk.end());
    return stk;
  }
};

// @lc code=start
/*
    DFS回溯法
*/
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    map<string, vector<string>> tmap;  // 路径查找表 from ->[to1,to2,...]
    map<string, vector<int>> visited;  // 访问标签，对于每个from节点，每个to节点是否已经访问
    for (vector<string>& ticket : tickets) {
      string& from = ticket[0];
      string& to = ticket[1];
      if (tmap.find(from) == tmap.end()) {
        tmap[from] = {};
        visited[from] = {};
      }
      tmap[from].emplace_back(to);
      visited[from].emplace_back(0);
    }
    // 按字典序排序，从而实现优先选取字典序小的节点
    for (auto& pair : tmap) {
      vector<string>& tos = pair.second;
      sort(tos.begin(), tos.end());
    }
    int cnt = 0;
    const int N = tickets.size();
    vector<vector<string>> result;
    vector<string> path;
    path.emplace_back("JFK");  // 起始节点为JFK
    backtrack(tmap, visited, 0, path, N, result);
    return result[0];
  }
  void backtrack(map<string, vector<string>>& tmap, map<string, vector<int>>& visited, int cnt,
                 vector<string>& path, const int N, vector<vector<string>>& result) {
    // 只返回一条结果，所以如果有结果，就没必要再继续了
    if (!result.empty()) {
      return;
    }
    // 所有路径全部访问全，这是符合条件的结果，记录结果并返回
    if (cnt >= N) {
      result.push_back(path);
      return;
    }
    string& from = path.back();
    vector<string>& tos = tmap[from];
    vector<int>& vis = visited[from];
    string p;
    // 对于当前节点的每个目标节点（如果已经有结果，就没必要遍历了）
    for (int i = 0; i < tos.size() && result.empty(); ++i) {
      // 剪枝，当前的节点的重复的目标节点只访问一次
      if (i > 0 && tos[i] == p) {
        continue;
      }
      // 如果从当前节点的目标节点还未访问过
      if (!vis[i]) {
        // 目标节点加入，将目标节点当成当前节点继续判断
        vis[i] = 1;
        path.emplace_back(tos[i]);
        backtrack(tmap, visited, cnt + 1, path, N, result);
        path.pop_back();
        vis[i] = 0;
        p = tos[i];
      }
    }
    return;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<string>> tickets{
      {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "JFK"}, {"ATL", "AAA"}, {"AAA", "BBB"},
      {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"},
      {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"},
      {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"},
      {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"},
      {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"},
      {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"},
      {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"},
      {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"},
      {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"},
      {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"},
      {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"},
      {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"},
      {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"},
      {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"},
      {"ATL", "AAA"}, {"AAA", "BBB"}, {"BBB", "ATL"}, {"ATL", "AAA"}, {"AAA", "BBB"},
      {"BBB", "ATL"}};
  s.findItinerary(tickets);
  return 0;
}
