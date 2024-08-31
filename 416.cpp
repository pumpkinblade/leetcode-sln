#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
  bool canPartition(std::vector<int> &nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>{});
    if (sum & 1)
      return false;
    int target = sum / 2;

    // opt[n][v] = it is possible to build `v` using nums[0..n] ?
    // opt[n][v] = opt[n-1][v - nums[n]] | opt[n-1][v]
    std::vector<std::vector<bool>> opt(nums.size(),
                                       std::vector<bool>(1 + target, false));
    opt[0][0] = true;
    for (int i = 1; i < nums.size(); i++) {
      for (int v = 0; v <= target; v++) {
        opt[i][v] = opt[i - 1][v] || (v >= nums[i] && opt[i - 1][v - nums[i]]);
      }
    }
    return opt.back().back();
  }
};

int main(void) {
  std::vector<int> nums = {2, 2, 3, 5};
  bool ans = Solution{}.canPartition(nums);
  std::cout << std::boolalpha << ans << '\n';
  return 0;
}
