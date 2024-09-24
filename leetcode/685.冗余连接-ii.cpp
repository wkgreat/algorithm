/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

#include <vector>

using namespace std;

// @lc code=start
/*
官方题解：使用并查集
在一棵树中，边的数量比节点的数量少 1。如果一棵树有 n 个节点，则这棵树有 n−1
条边。这道题中的图在树的基础上多了一条附加的边，因此边的数量也是 n。
树中的每个节点都有一个父节点，除了根节点没有父节点。在多了一条附加的边之后，可能有以下两种情况：
1. 附加的边指向根节点，则包括根节点在内的每个节点都有一个父节点，此时图中一定有环路；
2.
附加的边指向非根节点，则恰好有一个节点（即被附加的边指向的节点）有两个父节点，此时图中可能有环路也可能没有环路。
要找到附加的边，需要遍历图中的所有的边构建出一棵树，在构建树的过程中寻找导致冲突（即导致一个节点有两个父节点）的边以及导致环路出现的边。
*/
// 并查集
struct UnionFind {
  vector<int> ancestor;

  UnionFind(int n) {
    ancestor.resize(n);
    for (int i = 0; i < n; ++i) {
      ancestor[i] = i;
    }
  }

  int find(int index) {
    return index == ancestor[index] ? index : ancestor[index] = find(ancestor[index]);
  }

  void merge(int u, int v) { ancestor[find(u)] = find(v); }
};

class Solution {
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFind uf = UnionFind(n + 1);
    auto parent = vector<int>(n + 1);  // parent用于做父节点冲突检测
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    int conflict = -1;
    int cycle = -1;
    for (int i = 0; i < n; ++i) {
      auto edge = edges[i];
      int node1 = edge[0], node2 = edge[1];
      if (parent[node2] != node2) {  // 已经有父节点，在添加这条边，会导致有两个父节点
        conflict = i;
      } else {
        parent[node2] = node1;
        if (uf.find(node1) == uf.find(node2)) {  // 导致回路
          cycle = i;
        } else {
          uf.merge(node1, node2);
        }
      }
    }
    if (conflict < 0) {  // 有回路
      auto redundant = vector<int>{edges[cycle][0], edges[cycle][1]};
      return redundant;
    } else {  // 有两个父节点
      auto conflictEdge = edges[conflict];
      if (cycle >= 0) {  // 有回路
        auto redundant = vector<int>{parent[conflictEdge[1]], conflictEdge[1]};
        return redundant;
      } else {  // 无回路
        auto redundant = vector<int>{conflictEdge[0], conflictEdge[1]};
        return redundant;
      }
    }
  }
};
// @lc code=end
