/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

#include <vector>

using namespace std;

// @lc code=start
/* 官方题解
 首先迭代x+y=k
 选出nums1的最大子序列长度为x
 选出nums2的最大子序列长度为y
 子序列合并成一个当前结果序列
 取最大的结果序列作为最终结果
*/
class Solution {
 public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> maxSubsequence(k, 0);
    int start = max(0, k - n), end = min(k, m);
    for (int i = start; i <= end; i++) {
      vector<int> subsequence1(MaxSubsequence(nums1, i));
      vector<int> subsequence2(MaxSubsequence(nums2, k - i));
      vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
      if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
        maxSubsequence.swap(curMaxSubsequence);
      }
    }
    return maxSubsequence;
  }

  // 单调栈求最大子序列
  vector<int> MaxSubsequence(vector<int>& nums, int k) {
    int length = nums.size();
    vector<int> stack(k, 0);
    int top = -1;
    int remain = length - k;  // 栈内元素+未遍历元素个数
    for (int i = 0; i < length; i++) {
      int num = nums[i];
      while (top >= 0 && stack[top] < num && remain > 0) {
        top--;  // 弹出栈顶
        remain--;
      }
      if (top < k - 1) {
        stack[++top] = num;  // 压入栈顶
      } else {
        remain--;
      }
    }
    return stack;
  }

  // 两序列合并
  vector<int> merge(vector<int>& subsequence1, vector<int>& subsequence2) {
    int x = subsequence1.size(), y = subsequence2.size();
    if (x == 0) {
      return subsequence2;
    }
    if (y == 0) {
      return subsequence1;
    }
    int mergeLength = x + y;
    vector<int> merged(mergeLength);
    int index1 = 0, index2 = 0;
    for (int i = 0; i < mergeLength; i++) {
      if (compare(subsequence1, index1, subsequence2, index2) > 0) {
        merged[i] = subsequence1[index1++];
      } else {
        merged[i] = subsequence2[index2++];
      }
    }
    return merged;
  }

  // 序列比较
  int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2) {
    int x = subsequence1.size(), y = subsequence2.size();
    while (index1 < x && index2 < y) {
      int difference = subsequence1[index1] - subsequence2[index2];
      if (difference != 0) {
        return difference;
      }
      index1++;
      index2++;
    }
    return (x - index1) - (y - index2);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> num1{3, 4, 6, 5};
  vector<int> num2{9, 1, 2, 5, 8, 3};
  vector<int> r = s.maxNumber(num1, num2, 5);
  return 0;
}
