#include <iostream>
#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    int zc = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        zc++;
      } else {
        nums[i - zc] = nums[i];
      }
    }
    for (int i = nums.size() - zc; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};

int main(void) {
  std::vector<int> nums = {0};
  Solution{}.moveZeroes(nums);
  for (auto x : nums) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}
