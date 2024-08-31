#include <iostream>
#include <vector>

class Solution {
public:
  int rob(std::vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];

    int n = nums.size();
    std::vector<int> opt(n);
    opt[0] = nums[0];
    opt[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      // opt[i] = nums[i] + max{opt[i-2], opt[i-3], opt[i-4], ...}
      opt[i] = nums[i] + opt[i - 2];
      opt[i] = std::max(opt[i], opt[i - 1]);
    }
    return opt[n - 1];
  }
};

int main(void) {
  std::vector<int> nums = {2, 1, 1, 2};
  int res = Solution{}.rob(nums);
  std::cout << res << '\n';
  return 0;
}
