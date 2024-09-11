/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// 自己的答案
class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return nullptr;
    }
    set<Node*> visit;           // 是否访问过
    map<Node*, Node*> nodemap;  // 新旧节点对应关系
    queue<Node*> q;             // 广度搜索

    // 创建头节点 并访问头节点
    Node* r = new Node(node->val);
    nodemap[node] = r;
    r->val = node->val;
    visit.insert(node);
    for (Node* d : node->neighbors) {
      q.push(d);
      Node* t = new Node(d->val);
      r->neighbors.push_back(t);
      nodemap[d] = t;
    }

    // 广度搜索
    while (!q.empty()) {
      // 弹出当前节点
      Node* oldcur = q.front();
      q.pop();
      // 当前节点对应的新节点
      Node* newcur = nodemap[oldcur];

      // 当前节点未访问过
      if (visit.find(oldcur) == visit.end()) {
        // 当前节点每个子节点
        for (Node* t : oldcur->neighbors) {
          // 子节点未访问过
          if (visit.find(t) == visit.end()) {
            // 如果没有对应关系，则还未创建新节点，创建
            if (nodemap.find(t) == nodemap.end()) {
              nodemap[t] = new Node(t->val);
            }
            q.push(t);  // 将当前节点的子节点推入队列，供后续访问
          }
          // 当前新节点推入子节点
          newcur->neighbors.push_back(nodemap[t]);
        }
        // 当前节点标识为已经访问
        visit.insert(oldcur);
      }
    }
    return r;
  }
};
// @lc code=end

/*
官方题解 - 深度遍历
*/
class Solution1 {
 public:
  unordered_map<Node*, Node*> visited;
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return node;
    }

    // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
    if (visited.find(node) != visited.end()) {
      return visited[node];
    }

    // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
    Node* cloneNode = new Node(node->val);
    // 哈希表存储
    visited[node] = cloneNode;

    // 遍历该节点的邻居并更新克隆节点的邻居列表
    for (auto& neighbor : node->neighbors) {
      cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
    }
    return cloneNode;
  }
};

/*
官方题解 - 广度遍历
*/
class Solution2 {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return node;
    }

    unordered_map<Node*, Node*> visited;

    // 将题目给定的节点添加到队列
    queue<Node*> Q;
    Q.push(node);
    // 克隆第一个节点并存储到哈希表中
    visited[node] = new Node(node->val);

    // 广度优先搜索
    while (!Q.empty()) {
      // 取出队列的头节点
      auto n = Q.front();
      Q.pop();
      // 遍历该节点的邻居
      for (auto& neighbor : n->neighbors) {
        if (visited.find(neighbor) == visited.end()) {
          // 如果没有被访问过，就克隆并存储在哈希表中
          visited[neighbor] = new Node(neighbor->val);
          // 将邻居节点加入队列中
          Q.push(neighbor);
        }
        // 更新当前节点的邻居列表
        visited[n]->neighbors.emplace_back(visited[neighbor]);
      }
    }

    return visited[node];
  }
};
