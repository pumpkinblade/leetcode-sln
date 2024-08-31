#include <iostream>
#include <vector>

class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    int count = 0, candidate;
    for (int i = 0; i < nums.size(); i++) {
      if (count == 0) {
        candidate = nums[i];
      }
      if (candidate == nums[i]) {
        count++;
      } else {
        count--;
      }
    }
    return candidate;
  }
};

int main(void) {
  std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
  int k = Solution{}.majorityElement(nums);
  std::cout << k << '\n';
  return 0;
}
