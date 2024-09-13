/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  double dfs(map<string, map<string, double>>& edges, set<string>& vis, string s, string t) {
    // 如果节点不在图中, 则没有答案，返回-1;
    if (edges.find(s) == edges.end() || edges.find(t) == edges.end()) {
      return -1;
    }
    // 相同的数相除等于1
    if (s == t) {
      return 1;
    }
    map<string, double>& ds = edges[s];
    // 如果可以直达终点，则直接返回
    if (ds.find(t) != ds.end()) {
      return ds[t];
    }
    double k;
    // 每个后续节点
    for (auto& e : ds) {
      if (vis.find(e.first) == vis.end()) {  // 不走回头路
        vis.insert(e.first);
        k = dfs(edges, vis, e.first, t);  // 判断下一层
        vis.erase(e.first);
        // 如果值不为-1，则有答案，返回
        if (k != -1) {
          return k * e.second;
        }
      }
    }
    // 找不到答案返回-1，（因为图不联通）
    return -1;
  }
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                              vector<vector<string>>& queries) {
    map<string, map<string, double>> edges;
    for (int i = 0; i < equations.size(); ++i) {
      string& u = equations[i][0];
      string& d = equations[i][1];
      double v = values[i];
      // 构建图
      // map<u,map<d,v>> --> u/d = v
      // map<v,map<d,u>> --> u/d = 1/v
      if (edges.find(u) == edges.end()) {
        edges[u] = {{d, v}};
      } else {
        edges[u][d] = v;
      }
      if (edges.find(d) == edges.end()) {
        edges[d] = {{u, 1 / v}};
      } else {
        edges[d][u] = 1 / v;
      }
    }
    vector<double> r;
    set<string> vis;
    // 对每一个查询求解
    for (vector<string>& q : queries) {
      r.emplace_back(dfs(edges, vis, q[0], q[1]));
    }
    return r;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<string>> equations{{"a", "b"}, {"b", "c"}, {"a", "c"}, {"d", "e"}};
  vector<double> values{2.0, 3.0, 6.0, 1.0};
  vector<vector<string>> queries{{"a", "c"}, {"b", "c"}, {"a", "e"},
                                 {"a", "a"}, {"x", "x"}, {"a", "d"}};
  vector<double> r = s.calcEquation(equations, values, queries);
  return 0;
}
