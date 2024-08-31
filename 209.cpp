#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  int minSubArrayLen(int target, std::vector<int> &nums) {
    int p = 0, q = 0;
    int sum = 0;
    while (q < nums.size() && sum < target) {
      sum += nums[q++];
    }
    if (sum < target)
      return 0;

    int len = q - p;
    while (p < nums.size()) {
      if (sum >= target) {
        len = std::min(len, q - p);
      }
      if (sum < target && q < nums.size()) {
        sum += nums[q];
        q++;
      } else {
        sum -= nums[p];
        p++;
      }
    }
    return len;
  }
};

int main(void) {
  std::vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  int target = 11;
  int len = Solution{}.minSubArrayLen(target, nums);
  std::cout << len << '\n';
  return 0;
}
