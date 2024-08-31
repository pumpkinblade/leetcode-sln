#include <iostream>
#include <vector>

class Solution {
public:
  void nextPermutation(std::vector<int> &nums) {
    int k = -1;
    for (int i = 0; i < nums.size() - 1; i++) {
      k = nums[i] < nums[i + 1] ? i : k;
    }
    if (k == -1) {
      for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
        std::swap(nums[i], nums[j]);
      }
      return;
    }
    int l = k + 1;
    for (int i = k + 2; i < nums.size(); i++) {
      l = nums[i] > nums[k] ? i : l;
    }
    std::swap(nums[k], nums[l]);
    for (int i = k + 1, j = nums.size() - 1; i < j; i++, j--) {
      std::swap(nums[i], nums[j]);
    }
  }
};

int main(void) {
  std::vector<int> nums = {3, 2, 1};
  Solution{}.nextPermutation(nums);
  for (auto x : nums) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}
