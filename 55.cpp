#include <iostream>
#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    std::vector<bool> can(nums.size());
    can.back() = true;
    for (int i = nums.size() - 2; i >= 0; i--) {
      can[i] = false;
      for (int k = 1; k <= nums[i] && i + k < nums.size(); k++) {
        if (can[i + k]) {
          can[i] = true;
          break;
        }
      }
    }
    return can.front();
  }

  bool canJumpGreedy(std::vector<int> &nums) {
    int far = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (far < i)
        return false;
      far = std::max(far, i + nums[i]);
    }
    return true;
  }
};

int main(void) {
  std::vector<int> nums{2, 3, 1, 1, 4};
  bool can = Solution{}.canJump(nums);
  std::cout << std::boolalpha << can << '\n';
}
