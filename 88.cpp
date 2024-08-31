#include <iostream>
#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int k = m + n;
    while (m && n) {
      nums1[--k] = nums1[m - 1] > nums2[n - 1] ? nums1[--m] : nums2[--n];
    }
    while (n) {
      nums1[--k] = nums2[--n];
    }
  }
};

int main(void) {
  std::vector<int> nums1{0};
  std::vector<int> nums2{1};
  Solution{}.merge(nums1, 0, nums2, 1);
  for (int i = 0; i < nums1.size(); i++) {
    std::cout << nums1[i] << " ";
  }
  std::cout << '\n';
  return 0;
}
