#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  // int lengthOfLIS(std::vector<int> &nums) {
  //   int n = nums.size();
  //   int maxlen = 1;
  //   std::vector<int> opt(n);
  //   opt.front() = 1;
  //   for (int i = 1; i < n; i++) {
  //     int l = 1;
  //     for (int j = 0; j < i; j++) {
  //       if (nums[j] < nums[i]) {
  //         l = std::max(l, 1 + opt[j]);
  //       }
  //     }
  //     opt[i] = l;
  //     maxlen = std::max(maxlen, l);
  //   }
  //   // for (int i = 0; i < n; i++) {
  //   //   std::cout << opt[i] << ' ';
  //   // }
  //   // std::cout << '\n';
  //   return maxlen;
  // }

  int lengthOfLIS(std::vector<int> &nums) {
    // d[i] = 长度为 i 的所有递增子序列中最小末尾元素
    // d 严格递增
    int n = nums.size();
    int maxlen = 0;
    std::vector<int> d(n + 1);
    d[0] = std::numeric_limits<int>::min();
    for (int x : nums) {
      if (d[maxlen] < x) {
        d[++maxlen] = x;
      } else {
        auto it = std::lower_bound(d.begin(), d.begin() + maxlen + 1, x);
        int k = std::distance(d.begin(), it);
        // d[k - 1] <= x < d[k] // upper_bound
        // d[k - 1] < x <= d[k] // lower_bound
        d[k] = x;
      }
    }
    return maxlen;
  }
};

int main(void) {
  std::vector<int> nums = {4, 10, 4, 3, 8, 9};
  int res = Solution{}.lengthOfLIS(nums);
  std::cout << res << '\n';
  return 0;
}
