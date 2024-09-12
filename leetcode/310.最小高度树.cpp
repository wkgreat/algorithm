/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
/*
官方题解1 - 按深度搜索
注意题解中的推理
*/
class Solution {
public:
    int findLongestNode(int u, vector<int> & parent, vector<vector<int>>& adj) {
        int n = adj.size();
        queue<int> qu;
        vector<bool> visit(n);
        qu.emplace(u);
        visit[u] = true;
        int node = -1;
  
        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            node = curr;
            for (auto & v : adj[curr]) {
                if (!visit[v]) {
                    visit[v] = true;
                    parent[v] = curr;
                    qu.emplace(v);
                }
            }
        }
        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto & edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        
        vector<int> parent(n, -1);
        /* 找到与节点 0 最远的节点 x */
        int x = findLongestNode(0, parent, adj);
        /* 找到与节点 x 最远的节点 y */
        int y = findLongestNode(x, parent, adj);
        /* 求出节点 x 到节点 y 的路径 */
        vector<int> path;
        parent[x] = -1;
        while (y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return {path[m / 2 - 1], path[m / 2]};
        } else {
            return {path[m / 2]};
        }
    }
};
// @lc code=end

/*
官方题解2 - 广度搜索
*/
class OfficialSolution2 {
public:
    void dfs(int u, vector<int> & dist, vector<int> & parent, const vector<vector<int>> & adj) {
        for (auto & v : adj[u]) {
            if (dist[v] < 0) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                dfs(v, dist, parent, adj); 
            }
        }
    }

    int findLongestNode(int u, vector<int> & parent, const vector<vector<int>> & adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        dist[u] = 0;
        dfs(u, dist, parent, adj);
        int maxdist = 0;
        int node = -1;
        for (int i = 0; i < n; i++) {
            if (dist[i] > maxdist) {
                maxdist = dist[i];
                node = i;
            }
        }
        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto & edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> parent(n, -1);
        /* 找到距离节点 0 最远的节点  x */
        int x = findLongestNode(0, parent, adj);
        /* 找到距离节点 x 最远的节点  y */
        int y = findLongestNode(x, parent, adj);
        /* 找到节点 x 到节点 y 的路径 */
        vector<int> path;
        parent[x] = -1;
        while (y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return {path[m / 2 - 1], path[m / 2]};
        } else {
            return {path[m / 2]};
        }
    }
};

/*
官方题解3 - 拓扑排序
*/
class OfficalSolution3 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (auto & edge : edges){
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> qu;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                qu.emplace(i);
            }
        }
        int remainNodes = n;
        while (remainNodes > 2) {
            int sz = qu.size();
            remainNodes -= sz;
            for (int i = 0; i < sz; i++) {
                int curr = qu.front();
                qu.pop();
                for (auto & v : adj[curr]) {
                    if (--degree[v] == 1) {
                        qu.emplace(v);
                    }
                }
            }
        }
        while (!qu.empty()) {
            ans.emplace_back(qu.front());
            qu.pop();
        }
        return ans;
    }
};

/*
⏱❌弗洛伊德算法超时
*/
class Solution1 {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> matrix(n, vector<int>(n, 10E6));
    for (int i = 0; i < n; ++i) {
      matrix[i][i] = 0;
    }
    for (vector<int> edge : edges) {
      matrix[edge[0]][edge[1]] = 1;
      matrix[edge[1]][edge[0]] = 1;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          int s = matrix[j][i] + matrix[i][k];
          if (s < matrix[j][k]) {
            matrix[j][k] = s;
          }
        }
      }
    }
    int d = INT_MAX;
    for (vector<int> v : matrix) {
      int t = *max_element(v.begin(), v.end());
      if (t < d) {
        d = t;
      }
    }
    vector<int> r;
    for (int i = 0; i < n; ++i) {
      vector<int>& v = matrix[i];
      int t = *max_element(v.begin(), v.end());
      if (t == d) {
        r.push_back(i);
      }
    }
    return r;
  }
};

/*
⏱❌ 每个节点按深度搜索也超时
*/
class Solution2 {
 public:
  int nodeDepth(map<int, vector<int>>& edgemap, int a, int p, int d) {
    int c = 0;
    for (int e : edgemap[a]) {
      if (e != p) {
        c = max(c, nodeDepth(edgemap, e, a, d + 1));
      }
    }
    return d + c;
  }
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    map<int, vector<int>> edgemap;
    for (int i = 0; i < n; ++i) {
      edgemap[i] = {};
    }
    for (vector<int>& edge : edges) {
      edgemap[edge[0]].push_back(edge[1]);
      edgemap[edge[1]].push_back(edge[0]);
    }
    vector<int> depth(n, 0);
    for (int i = 0; i < n; ++i) {
      depth[i] = nodeDepth(edgemap, i, -1, 0);
    }
    int m = *min_element(depth.begin(), depth.end());
    vector<int> r;
    for (int i = 0; i < n; ++i) {
      if (depth[i] == m) {
        r.push_back(i);
      }
    }
    return r;
  }
};
