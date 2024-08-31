#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int findK(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
    int i = 0, j = 0;
    int m = nums1.size(), n = nums2.size();
    while (i < m && j < n && k > 1) {
      int p = k / 2;
      int x = i + p - 1 < nums1.size() ? nums1[i + p - 1]
                                       : std::numeric_limits<int>::max();
      int y = j + p - 1 < nums2.size() ? nums2[j + p - 1]
                                       : std::numeric_limits<int>::max();
      if (x < y)
        i += p;
      else
        j += p;
      k -= p;
    }
    if (i >= m) {
      return nums2[j + k - 1];
    }
    if (j >= n) {
      return nums1[i + k - 1];
    }
    return std::min(nums1[i], nums2[j]);
  }

  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    int k1 = (nums1.size() + nums2.size()) / 2;
    int k2 = (nums1.size() + nums2.size() + 1) / 2;
    return (findK(nums1, nums2, k1) + findK(nums1, nums2, k2)) / 2.0;
  }
};

int main(void) {
  std::vector<int> nums1 = {1, 3, 5, 7};
  std::vector<int> nums2 = {2, 4, 6, 8, 10, 12, 14, 16};
  int valK = Solution{}.findK(nums1, nums2, 8);
  std::cout << valK << '\n';
  return 0;
}
