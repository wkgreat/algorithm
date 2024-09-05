/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
/*
题解：
https://leetcode.cn/problems/gas-station/solutions/1/shi-yong-tu-de-si-xiang-fen-xi-gai-wen-ti-by-cyayc/?source=vscode
*/
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int s = 0;
    int mins = INT_MAX;
    int mini = 0;
    for (int i = 0; i < n; ++i) {
      s += gas[i] - cost[i];
      if (s < mins) {
        mins = s;
        mini = i;
      }
    }
    return s < 0 ? -1 : (mini + 1) % n;
  }
};
// @lc code=end

/*
官方题解1：
一句话概括：
如果x到达不了y+1，
那么x-y之间的点也不可能到达y+1，
因为中间任何一点的油都是拥有前面的余量的，
所以下次遍历直接从y+1开始
*/
class Solution0 {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int i = 0;
    while (i < n) {
      int r = 0;
      bool b = true;
      int j = i;
      for (; j < i + n + 1; ++j) {
        r += gas[j % n] - cost[j % n];
        if (r < 0) {
          b = false;
          break;
        }
      }
      if (b) {
        return i;
      } else {
        i = j + 1;
      }
    }
    return -1;
  }
};
