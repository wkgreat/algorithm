/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

#include <map>
#include <vector>

using namespace std;

// @lc code=start
/*
官方题解 - 并查集

在一棵树中，边的数量比节点的数量少 1。如果一棵树有 n 个节点，则这棵树有 n−1
条边。这道题中的图在树的基础上多了一条附加的边，因此边的数量也是 n。

树是一个连通且无环的无向图，在树中多了一条附加的边之后就会出现环，因此附加的边即为导致环出现的边。

可以通过并查集寻找附加的边。初始时，每个节点都属于不同的连通分量。遍历每一条边，判断这条边连接的两个顶点是否属于相同的连通分量。

* 如果两个顶点属于不同的连通分量，则说明在遍历到当前的边之前，这两个顶点之间不连通，因此当前的边不会导致环出现，合并这两个顶点的连通分量。

* 如果两个顶点属于相同的连通分量，则说明在遍历到当前的边之前，这两个顶点之间已经连通，因此当前的边导致环出现，为附加的边，将当前的边作为答案返回。
*/
class Solution {
 public:
  int Find(vector<int>& parent, int index) {
    if (parent[index] != index) {
      parent[index] = Find(parent, parent[index]);
    }
    return parent[index];
  }

  void Union(vector<int>& parent, int index1, int index2) {
    parent[Find(parent, index1)] = Find(parent, index2);
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    // 边的个数，如果是树，则节点的个数=边的个数+1
    // 由于多了一条边，所以节点个数为边的个数+1
    int n = edges.size();
    // 节点编号从1开始，所以索引0不存数据，所以vector大小为n+1
    vector<int> parent(n + 1);
    // 初始化并查集
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    // 进行迭代
    for (auto& edge : edges) {
      int node1 = edge[0], node2 = edge[1];
      if (Find(parent, node1) != Find(parent, node2)) {
        Union(parent, node1, node2);
      } else {
        return edge;
      }
    }
    return vector<int>{};
  }
};
// @lc code=end
