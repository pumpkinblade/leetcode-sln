#include <iostream>
#include <vector>

class Solution {
public:
  int firstMissingPositive(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = 0 < nums[i] && nums[i] <= n ? nums[i] : -1;
    }
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      // if 0 < x <= n -> set nums[x - 1] = 0
      // if 0 < nums[x - 1] <= n -> set nums[nums[x - 1] - 1] = 0
      while (0 < x && x <= n) {
        int t = nums[x - 1];
        nums[x - 1] = 0;
        x = t;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0)
        return i + 1;
    }
    return nums.size() + 1;
  }
};

int main(void) {
  // std::vector<int> nums = {1, 2, 0};
  // std::vector<int> nums = {3, 4, -1, 1};
  // std::vector<int> nums = {7, 8, 9, 11, 12};
  // std::vector<int> nums = {2, 2, 3, 1};
  std::vector<int> nums = {2, 1};
  int ans = Solution{}.firstMissingPositive(nums);
  std::cout << ans << '\n';
  return 0;
}
