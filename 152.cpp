#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    // begin with the first number
    int prefixPositive = 1;
    // begin with the first number that after a negative number
    int prefixNegative = 0;
    // acc
    int acc = 1;
    // sign
    int sign = 1;
    int ans = std::numeric_limits<int>::min();
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        prefixPositive = 1;
        prefixNegative = 1;
        sign = 1;
        acc = 1;
        ans = std::max(ans, 0);
      } else if (nums[i] > 0) {
        acc *= nums[i];
      } else {
        if (sign > 0) {
          // + -> -
          sign = -1;
          prefixPositive *= acc;
          prefixNegative *= acc;
          prefixNegative *= nums[i];
          ans = std::max(ans, prefixNegative);
          acc = nums[i];
        } else {
          sign = 1;
          prefixPositive *= acc;
          prefixPositive *= nums[i];
          ans = std::max(ans, prefixPositive);
          acc = nums[i];
        }
      }
    }
    return static_cast<int>(ans);
  }
};

int main(void) {
  std::vector<int> nums = {0, 10, 10, 10, -10, 10, 10, 0};
  int ans = Solution{}.maxProduct(nums);
  std::cout << ans << '\n';
  return 0;
}
