/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    if (n + m == 1) {
      if (n == 1) {
        return nums1[0];
      } else {
        return nums2[0];
      }
    }
    int a, b;
    if ((n + m) % 2 == 0) {
      a = (n + m) / 2 - 1;
    } else {
      a = (n + m) / 2;
    }
    b = a + 1;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    auto p1 = nums1.begin();
    auto p2 = nums2.begin();
    auto p = p1;
    auto pa = p1;
    auto pb = p1;

    int k = 0;
    while (k <= b) {
      if (p1 == nums1.end()) {
        p = p2++;
      } else if (p2 == nums2.end()) {
        p = p1++;
      } else if (*p1 < *p2) {
        p = p1++;
      } else {
        p = p2++;
      }
      if (k == a) {
        pa = p;
      }
      if (k == b) {
        pb = p;
      }
      k++;
    }
    double r;
    if ((n + m) % 2 == 0) {
      r = (*pa + *pb) / 2.0;
    } else {
      r = *pa;
    }
    return r;
  }
};
// @lc code=end

int main() {
  std::vector<int> a{1, 3};
  std::vector<int> b{2};
  Solution s;
  double r = s.findMedianSortedArrays(a, b);
  std::cout << r << std::endl;
  return 0;
}
